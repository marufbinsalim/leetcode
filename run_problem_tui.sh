#!/bin/bash

# TUI for selecting and running LeetCode problems
# Uses arrow keys for navigation

# Get problem names in a formatted way
get_problem_info() {
    ls -d problem_* 2>/dev/null | while read -r dir; do
        problem_num=$(echo "$dir" | sed 's/problem_//' | sed 's/_.*//')
        problem_name=$(echo "$dir" | sed 's/problem_[0-9]*_//' | tr '_' ' ')
        if [ -z "$problem_name" ]; then
            problem_name="Unknown"
        fi
        echo "$problem_num|$problem_name|$dir"
    done | sort -V
}

# Draw the menu
draw_menu() {
    local current_selection=$1
    local filter_input=$2
    shift 2
    local problems=("$@")

    clear

    echo -e "\033[1;34m╔══════════════════════════════════════════════════════════════╗\033[0m"
    echo -e "\033[1;34m║                    LeetCode Problem Runner                    ║\033[0m"
    echo -e "\033[1;34m║                   Use ↑↓ arrows to navigate                   ║\033[0m"
    echo -e "\033[1;34m║              Filter: $filter_input\033[0m"
    echo -e "\033[1;34m║          Type to filter, Enter to run, Ctrl+Q to quit         ║\033[0m"
    echo -e "\033[1;34m╚══════════════════════════════════════════════════════════════╝\033[0m"
    echo

    local max_items=$(( $(tput lines) - 8 ))
    local start=0

    if [ $current_selection -ge $max_items ]; then
        start=$((current_selection - max_items + 1))
    fi

    for ((i=start; i<${#problems[@]} && i<start+max_items; i++)); do
        IFS='|' read -r problem_num problem_name _ <<< "${problems[i]}"
        if [ $i -eq $current_selection ]; then
            echo -e "\033[1;47;30m  [$problem_num] $problem_name  \033[0m"
        else
            echo -e "  \033[90m[$problem_num]\033[0m $problem_name"
        fi
    done

    echo
    echo -e "\033[90m  Showing ${#problems[@]} / ${#problem_info[@]} problems\033[0m"
}

# Load problems
mapfile -t problem_info < <(get_problem_info)

if [ ${#problem_info[@]} -eq 0 ]; then
    echo "No problem directories found!"
    exit 1
fi

current_selection=0
filter_input=""
quit_flag=false

trap 'tput cnorm; clear' INT TERM EXIT
tput civis

while [ "$quit_flag" = false ]; do
    filtered_problems=()

    for problem in "${problem_info[@]}"; do
        if [[ "${problem,,}" == *"${filter_input,,}"* ]]; then
            filtered_problems+=("$problem")
        fi
    done

    if [ ${#filtered_problems[@]} -eq 0 ]; then
        filtered_problems=("${problem_info[@]}")
    fi

    if [ $current_selection -ge ${#filtered_problems[@]} ]; then
        current_selection=0
    fi

    draw_menu "$current_selection" "$filter_input" "${filtered_problems[@]}"

    read -rsn1 key

    case "$key" in
        $'\x1b')
            read -rsn1 -t 0.1 key2
            [[ $key2 == "[" ]] || continue
            read -rsn1 -t 0.1 key3
            case "$key3" in
                A) ((current_selection > 0)) && ((current_selection--)) ;;
                B) ((current_selection < ${#filtered_problems[@]} - 1)) && ((current_selection++)) ;;
            esac
            ;;
        $'\x11')
            quit_flag=true
            ;;
        $'\x7f'|$'\b')
            filter_input="${filter_input%?}"
            current_selection=0
            ;;
        "")
            IFS='|' read -r problem_num problem_name _ <<< "${filtered_problems[$current_selection]}"
            clear
            echo -e "\033[1;32mRunning [$problem_num] $problem_name...\033[0m"
            tput cnorm
            ./run_problem.sh "$problem_num"
            echo
            read -rsn1 -p "Press any key to return..."
            tput civis
            ;;
        *)
            filter_input+="$key"
            current_selection=0
            ;;
    esac
done
