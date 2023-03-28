$prefix=$MyInvocation.MyCommand.Name.Split(".")[0]
$files = (Get-ChildItem -Path ./* -Include "${prefix}_*_input.txt").Name
g++ -fdiagnostics-color=always -g "${pwd}\$prefix.cpp" -o "${pwd}\$prefix.exe"

foreach ($file in $files) {
    $num = $file.Split("_")[2]
    Write-Output "===== Input #${num} ====="
    $r = Compare-Object -ReferenceObject (Get-Content -Path "./${prefix}_${num}_output.txt") -DifferenceObject (Invoke-Expression "Get-Content ${prefix}_${num}_input.txt | .\$prefix.exe") 
    if ($null -eq $r) { Write-Output "Congratulations! Correct!" } else { 
        Write-Output "XXX! Incorrect......" 
        Write-Output $r
    }
    Write-Output ""
}
