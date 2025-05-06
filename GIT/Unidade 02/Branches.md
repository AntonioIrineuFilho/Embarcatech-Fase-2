# Rseumo Branches

## Comandos

* ``git branch`` lista as branches existentes.

* ``git branch nome-da-branch`` cria uma nova branch.

* ``git switch nome-da-branch ou git checkout nome-da-branch`` alterna entre branches.

* ``git switch -c nome-da-branch ou git checkout -b nome-da-branch`` cria e muda para a nova branch.

* ``git branch -d nome-da-branch`` exclui uma branch já mesclada.

* ``git branch -D nome-da-branch`` força a exclusão da branch, mesmo sem merge.

* ``git merge nome-da-branch`` realiza o merge da branch especificada na branch atual.

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

## Boas Práticas

* **Branches pequenas e objetivas**: tornam o código mais fácil de revisar e integram-se com menos atritos.

* **Nomenclatura padronizada**: ajuda na organização e localização das tarefas. Pode incluir prefixos como feature/, fix/, hotfix/, release/.

* **Integração contínua**: realizar merges frequentes evita divergências excessivas e facilita a resolução de conflitos.

* **Atualização da branch principal**: manter sua branch alinhada com main reduz riscos na hora de fazer merge.

* **Pull Requests ou Merge Requests**: são fundamentais para garantir revisão e validação do código antes da integração.

* ``git pull origin mainn`` para atualizar sua branch com as últimas mudanças da principal antes de fazer o merge.

## Gitflow

* **main**: contém o código de produção.

* **develop**: linha de desenvolvimento contínuo.

* **feature/***: criadas a partir de develop para o desenvolvimento de novas funcionalidades.

* **release/***: criadas para preparar uma nova versão a partir de develop, com ajustes finais antes de ir para main.

* **hotfix/***: criadas a partir de main para corrigir problemas críticos em produção.
