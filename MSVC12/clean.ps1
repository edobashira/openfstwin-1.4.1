if ($args.Count -ne 1)  {
    Write-Host "No input folder specified, if you continue the script will run in the current directory..." -ForegroundColor "Red"
    Read-Host ("Press Enter to Continue")
    $folderPath= [Environment]::CurrentDirectory=(Get-Location -PSProvider FileSystem).ProviderPath

}
else {
    $folderPath= $args[0]
}

#Modify the array below to delete more extensions
$extensionList = @(".svn", "svn", "suo","user","rc","tlog","idb","log","pdb","sdf","ilk","obj","ipch", "lastbuildstate", "unsuccessfulbuild", ".intermediate.manifest", "manifest.res", "manifest", "cache")

for ($start = 0; $start -le $extensionList.Count; $start++)  {
  $extension = '*.' + $extensionList[$start]
  Get-ChildItem $folderPath -include $extension -recurse | Remove-Item -force
}

get-childitem -Include .svn -Recurse -force | Remove-Item -Force -Recurse
#(get-childitem -recurse -force | where-object { $_.PsIsContainer -eq $true -and $_.Name -eq ".svn" } ) | remove-item –recurse –force