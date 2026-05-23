git fetch --all

$branches = git branch -r `
| Where-Object {
    $_ -match "origin/" `
    -and $_ -notmatch "HEAD" `
    -and $_ -notmatch "main"
} `
| ForEach-Object {
    ($_ -replace "origin/", "").Trim()
}

foreach ($branch in $branches) {

    Write-Host ""
    Write-Host "=============================="
    Write-Host "Actualizando rama: $branch"
    Write-Host "=============================="

    git checkout $branch

    git pull origin $branch

    git merge origin/main

    if ($LASTEXITCODE -ne 0) {

        Write-Host "Conflicto detectado en $branch"
        git merge --abort
        continue
    }

    $confirm = Read-Host "Push de $branch ? (y/n)"

    if ($confirm -eq "y") {
        git push origin $branch
    }
}

git checkout main

Write-Host ""
Write-Host "Proceso terminado."