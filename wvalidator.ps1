$arg = $args[0]
$scriptFileName=$MyInvocation.MyCommand.Name.Split(".")[0]
if ($null -eq $arg) {
    Write-Output "Provide CODE(e.g., 7D, 3C) of the problem as first parameter. Excute command like below."
    Write-Output "`t.\${scriptFileName} ""{code}"""
    Exit
}

$targetCpp = Get-ChildItem -Path "./${arg}*.cpp"
if ($null -eq $targetCpp) {
    Write-Output "Target ${scriptFileName}.cpp file does not exist."
    Exit
}
$prefix = $targetCpp.Name.Split('.')[0]
g++ -fdiagnostics-color=always -g "${pwd}\$prefix.cpp" -o "${pwd}\$prefix.exe"

$files = (Get-ChildItem -Path ./* -Include "${prefix}*input.txt").Name
if ($files.Length -eq 0) {
    Write-Output "Please make test input, output file for ${$prefix}"
    Exit
}
foreach ($file in $files) {
    $num = $file.Split("_")[2]

    # TODO Improve with regular expressions
    if (($num -as [int]) -isnot [int]) {
        Write-Output "Provided input & output file name does not match format.`nThe name format of Input & Output file should be as follows.`n`t${prefix}_1_input.txt`n`t${prefix}_1_output.txt"
        Exit
    }

    $error.Clear()
    try {
        $r = Compare-Object -ReferenceObject (Get-Content -Path "./${prefix}_${num}_output.txt") -DifferenceObject (Invoke-Expression "Get-Content ${prefix}_${num}_input.txt | .\$prefix.exe") 
        Write-Output "===== Input #${num} ====="
        if ($null -eq $r) { Write-Output "Congratulations! Correct!" } else { 
            Write-Output "XXX! Incorrect......" 
            Write-Output $r
        }
        Write-Output ""
    } catch {
        "Error Occurred while compare input & output files. Check the above error message."
        Exit
    }
}
