# Comandos Iniciais

* `` git --version `` -> mostra a versão instalada do git

* `` git init -b main `` -> inicializa um repositório local na branch main de um repositório do github, **utilizar quando não tiver dado clone e quiser conectar uma pasta local com o git, com a necessidade de especificar o repositório que deseja dar o push com** `` git remote add origin https://github.com/usuario/meu-repo.git ``

* `` git checkout -b branch_especifica origin/branch_especifica `` -> se quiser trabalhar com uma branch específica do repositório após o init, basta dar o remote add no repo da nuvem, e o comando checkout para definir a branch

* `` git config user.name 'User'`` -> altera o nome do usuário local do projeto

* `` git config user.email 'Email'`` -> altera o email do usuário local do projeto

* `` git config --list --local `` -> exibe as cofigurações locais do repositório

* `` git config --list --global `` -> exibe as configurações globais do git

* `` git status `` -> exibe o estado do repo local em relação ao da nuvem

* `` git add arquivo `` -> prepara um arquivo para subir

* `` git commit -m "mensagem" `` -> confirma o desejo de subir o arquivo com uma mensagem para a versão

* `` git push `` -> sobe o arquivo

* `` git log `` --oneline -> exibe os commits realizados


