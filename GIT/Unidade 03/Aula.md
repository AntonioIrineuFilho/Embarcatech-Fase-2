# Histórico e Restauração

* ```git log``` -> mostra o histórico de commits por:
  * Autor
  * Mensagem
  * Identificador Único(Código Hash)

* ```git log --oneline``` -> mostra cada commit em uma linha com o código hash reduzido.

* O código hash pode ser utilizado para visualizar o estado da branch naquele commit.

* ```git chechout <hash>``` -> muda o repositório local para a branch no momento daquele commit.

* ```git diff``` -> mostra se houve alguma alteração e se sim qual alteração na branch atual.

* ``` git diff <commit1> <commit2>``` -> mostra as diferenças entre commits especificos(hash).

* ```git revert <commit>``` -> retorna o commit especifico para uma versão anterior:
  * Não exclui o commit revertido do histórico(importante para linha do tempo de alterações)
  * Seguro para históricos compartilhados

* ```git reset --flag <commit>``` -> bom para excluir um commit local(sem push remoto):
  * Não mantém no histórico
  * Útil para caso deseje se desfazer de um commit local que não deseja subir
  * flag --soft -> remove o commit mas mantém as alterações no staging(basicamente no ponto do git add)
  * flag --mixed -> remove o commit e o staging mas mantém as alterações locais
  * flag --hard -> remove tudo, inclusive as alterações locais

 * **PARA COMMITS COM PUSH DAR REVERT, PARA COMMITS SEM PUSH(LOCAIS) DAR RESET**

 * ```git reflog``` -> mostra o histórico de movientação do HEAD(commits que foram atuais) permitindo recuperar os commits perdidos.

 * ```git stash``` -> salva modificações em uma área temporária, para caso queira mudar de branch para outra que não seja a branch fonte da atual:
   * Nesse caso, o git apontaria um erro, pois estaria tentando trocar de branch com alterações não commitadas na atual.
   * flag --list -> lista o que está guardado no stash daquela branch.

* ```git stash pop``` -> recupera o que está reservado naquela branch.

* ```git tag -a <nome>``` -> demarca um commit significativo(como um commit que indique uma versão pronta do sistema):

* ```git tag``` -> mostra todas as tags.

* ```git show <nome da tag>``` -> mostra as informações do commit associado a essa tag.

* ```git push origin <nome da tag>``` -> sobe o commit dessa tag para uma release no repositório.
