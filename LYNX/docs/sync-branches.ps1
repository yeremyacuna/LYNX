```powershell
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
    Write-Host "Rama encontrada: $branch"
    Write-Host "=============================="

    # Preguntar ANTES del merge
    $confirmMerge = Read-Host "Actualizar $branch con origin/main ? (y/n)"

    if ($confirmMerge -ne "y") {

        Write-Host "Rama omitida: $branch"
        continue
    }

    git checkout $branch

    git pull origin $branch

    # Merge sin abrir Vim
    git merge origin/main --no-edit

    if ($LASTEXITCODE -ne 0) {

        Write-Host "Conflicto detectado en $branch"

        git merge --abort

        continue
    }

    $confirmPush = Read-Host "Push de $branch ? (y/n)"

    if ($confirmPush -eq "y") {

        git push origin $branch

        Write-Host "Push realizado para $branch"
    }
    else {

        Write-Host "Push cancelado para $branch"
    }
}

git checkout main

Write-Host ""
Write-Host "Proceso terminado."
```
