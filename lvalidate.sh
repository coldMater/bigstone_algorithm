#!/bin/bash

# 입력 매개변수 가져오기
arg="$1"

# 스크립트 파일 이름 가져오기
scriptFileName="$(basename "$0" .sh)"

# 매개변수가 없을 경우 사용 방법 출력
if [ -z "$arg" ]; then
    echo "Provide CODE(e.g., 7D, 3C) of the problem as first parameter. Excute command like below."
    echo -e "\t./${scriptFileName}.sh {code}"
    exit 1
fi

# 대상 cpp 파일 찾기
targetCpp=$(find . -name "${arg}*.cpp" -type f)
if [ -z "$targetCpp" ]; then
    echo "Target ${scriptFileName}.cpp file does not exist."
    exit 1
fi

# cpp 파일 컴파일
prefix=$(basename "$targetCpp" .cpp)
g++ -fdiagnostics-color=always -g "$prefix.cpp" -o "$prefix.linux_excutable"

# 테스트 입력 및 출력 파일 가져오기
files=$(find . -name "${prefix}*input.txt" -type f)
if [ -z "$files" ]; then
    echo "Please make test input, output file for $prefix"
    exit 1
fi

# 테스트 입력 및 출력 파일 테스트 실행
for file in $files; do
    num=$(echo "$file" | sed 's/.*_\([0-9]*\)_input.txt/\1/')

    # 정규식으로 개선할 수 있는 부분이 있습니다.
    if ! [[ "$num" =~ ^[0-9]+$ ]]; then
        echo "Provided input & output file name does not match format."
        echo "The name format of Input & Output file should be as follows."
        echo -e "\t${prefix}_1_input.txt"
        echo -e "\t${prefix}_1_output.txt"
        exit 1
    fi

    # 입력 및 출력 파일 비교 실행
    errorMsg="Error Occurred while compare input & output files. Check the above error message."
    output=$(./"$prefix.linux_excutable" < "$prefix"_"$num"_input.txt | diff -Z - "$prefix"_"$num"_output.txt)
    error=$?

    # 결과 출력
    echo "===== Input #$num ====="
    if [ $error -eq 0 ]
    then
        echo "Congratulations! Correct!"
        exit 0
    elif [ $error -eq 1 ]
    then
        echo "XXX! Incorrect......"
        echo "$output"
        exit 1
    else
        echo "$errorMsg"
    fi
    exit $error
done
