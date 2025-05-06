# Rseumo Branches

## Comandos

``git branch`` lista as branches existentes.

``git branch nome-da-branch`` cria uma nova branch.

``git switch nome-da-branch ou git checkout nome-da-branch`` alterna entre branches.

``git switch -c nome-da-branch ou git checkout -b nome-da-branch`` cria e muda para a nova branch.

``git branch -d nome-da-branch`` exclui uma branch já mesclada.

``git branch -D nome-da-branch`` força a exclusão da branch, mesmo sem merge.

``git merge nome-da-branch`` realiza o merge da branch especificada na branch atual.

## Exemplos Sintaxe de Branches

* **feature/cadastro-usuario** nova funcionalidade.

* **bugfix/login-invalido** correção de erro.

* **hotfix/v1.2.1** correção emergencial em produção.

## Resolver Conflitos de Merge

* Surgem quando o sistema não consegue decidir automaticamente como mesclar mudanças feitas em paralelo em arquivos comuns. Quando isso ocorre, o Git interrompe o processo de merge e insere marcações especiais nos arquivos conflitantes:

````
<<<<<<< HEAD

conteúdo da branch atual

=======

conteúdo da outra branch

>>>>>>> nome-da-branch

````

* O desenvolvedor deve então abrir o(s) arquivo(s), analisar as diferenças, remover as marcações e editar o conteúdo de forma coerente. Após isso, o arquivo deve ser adicionado novamente à área de staging e o commit de merge pode ser finalizado.
