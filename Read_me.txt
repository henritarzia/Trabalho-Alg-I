-----------------------------------------
Alunos:
Henriqe Tadashi Tarzia n�:xxxxxxxx
Luiz Nome2 Nome3 Nome4 n�:xxxxxxxx
Lucas Xavier Ebling Pereira n�:10692183
-----------------------------------------

||GOOGLE BOT 2.0||


 ---------------------
 Instru��es de uso:
 ---------------------

 -> Pr�-Requisitos:
     Ap�s a compilacao de "cliente.c" garanta que em seu computador tambem ha o arquivo "googlebot.txt" na mesma pasta
   que se encontra esse arquivo, nosso zip j� traz uma pasta de tal nome com contudo para os testes necess�rios. O 
   conteudo dessa pasta pode ser mudado desde que ela mantenha o padrao nela presente.
                                              || O padrao: ||
              O texto sera sempre apresentado no padrao CSV (comma separated values) da seguinte maneira:
                                ||  codigo,nome,relevancia,link,palavras-chave ||
              - CODIGO: E um codigo numerico de quatro digitos entre 0000 e 1000, qualquer valor acima sera
              mostrado como um erro e deve ser modificado.
              - NOME: O nome e um conjunto de caracteres com um maximo de 50 caracteres, caracteres serao, de
              preferencia, do modelo ASCII apenas, outros sao permitidos, mas devido as caracteristicas de um 
              computador a outro, podem ocorrer problemas de inteligibilidade. O mesmo vale para todos as outras
              insercoes de palavras. 
              - RELEVANCIA: Valor numerico de quatro digitos entre 0000 e 1000, qualquer valor acima sera apre-
              sentado como erro e deve ser modificado.
              - LINK: O link sera o link do site, podendo ter, no maximo, 100 caracteres.
              - PALAVRAS CHAVE: As palavras chave sao palavras adicionais de no maximo 50 caracteres, e possivel
              ter no maximo 10 palavras chave, podendo tambem ter nenhuma. Tendo mais do que 10 palavras-chave, o
              programa acusara um erro.
                                                || Exemplo: ||
                           0001,YouTube,900,https://www.youtube.com/,youtube,videos,online
 -> Rodando o Programa:
     ||A determinar|| No inicio do progama as informa��es de googlebot.txt ser�o lidas, se qualquer informacao 
   for errada, isto �, fora dos padroes, uma mensagem de erro aparecera e a informacao com o erro n�o ser� inse-
   rida no programa. Recomendamos que, ao colocar informa��es no arquivo, siga o padr�o estabelecido.

 -> O Menu:
  	A seguir sera apresentado o layout do menu:
                                 || MENU: ||
                    ||     1) Inserir site          ||
                    ||     2) Remover site          || 
                    ||     3) Inserir chave         ||
                    ||     4) Atualizar relevancia  ||
                    ||     5) Imprimir sites        ||
                    ||     6) Buscar palavra        ||
                    ||     7) Sair                  ||

 	A seguir ser�o apresentadas informa��es sobre cada uma das opera��es poss�veis no programa:
   	<1)> Inserir site:
		Selecionando esta op��o o usu�rio poder� inserir um novo site no programa, tal site ser� organizado
	em ordem de c�digo com os outros sites j� presentes. � necess�rio que as informa��es inseridas sejam v�lidas
  	pois, caso o contr�rio, uma mensagem de erro ocorrera e o site n�o ser� inserido. 
        <2)> Remover site: 
		Ao selecionar essa opcao o usu�rio poder�, dado um c�digo valido, retirar um dos sites da lista. Se
	o c�digo n�o for v�lido, uma mensagem de erro ocorrera e o usuario tera de tentar novamente. 
        <3)> Inserir chave:
    		Com essa op��o o usu�rio pode, tendo um c�digo v�lido, inserir uma nova palavra-chave no site escolhido.
	Da mesma maneira que os casos anteriores, se o c�digo n�o existir uma mensagem de erro aparecer� e o usu�rio 
	ter� de selecionar a op��o novamente.
	<4)> Atualizar relevancia: 
		Com esse, dado um c�digo v�lido, o usu�rio poderp� mudar a relev�ncia de um site selecionado. Novamente,
	o c�digo h� de ser v�lido, se n�o for uma mensagem de erro aparecer� e o usu�rio tera de fazer o processo novamente.
	Igualmente, num caso de relevancia inv�lida, o usu�iro receber� uma mensagem de erro e ter� de refazer o processo.
	<5)> Imprimir sites:
		Selecionando Imprimir sites o usu�rio imprimir� todos os sites presentes na �rvore, os sites ser�o impressos
	em percurso em ordem. 
	<6> Buscar palavra:
		Dada uma palavra-chave, essa op��o ir� imprimir (em ordem) todos os sites que possuem dita palavra chave. Caso a
	palavra-chave selecionada n�o esteja contida em nenhum site, nada ser� impresso. 
	<7)> Sair:
		Selecionar essa op��o finalizar� o programa, nada mais pode ser feito ap�s selecionar essa op��o. 





	LUCAS --->> O que fazer
      	-> Terminar o READ_ME
       	-> Fazer os displays de erro para minha funcao e outras; 