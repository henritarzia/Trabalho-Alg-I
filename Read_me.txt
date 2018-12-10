-----------------------------------------
Alunos:
Henrique Tadashi Tarzia n�:10692210
Lu�s Felipe Riveiro Chaves n�:10801221
Lucas Xavier Ebling Pereira n�:10692183
-----------------------------------------

||GOOGLE BOT 2.0||


 ---------------------
 Instru��es de uso:
 ---------------------

 -> Pr�-Requisitos:
     Ap�s a compilacao de "cliente.c", garanta que em seu computador tamb�m h� o arquivo "googlebot.txt" na mesma pasta
   que se encontra esse arquivo, nosso zip j� traz uma pasta de tal nome com tudo necess�rio para os testes. O 
   conte�do dessa pasta, pode ser mudado desde que ela mantenha o padr�o nela presente.
                                              ||O padr�o:||
              O texto sera sempr� apresentado no padrao CSV (comma separated values) da seguinte maneira:
                                ||c�digo,nome,relev�ncia,link,palavras-chave||
              - C�DIGO: � um c�digo num�rico de quatro d�gitos entre 0000 e 1000, qualquer valor acima ser�
              mostrado como um erro e deve ser modificado.
              - NOME: O nome � um conjunto de no m�ximo 50 caracteres que devem ser, preferencialmente, do modelo ASCII.
	      Outros tipos de carcteres s�o permitidos, mas devido �s diferen�as entre computadores, pode ocorrer problemas de inteligibilidade.
              - RELEV�NCIA: Valor num�rico entre 0000 e 1000 (valores acima ser�o gerar�o erro e dever�o ser adaptados).
              - LINK: O link � o link do site, podendo ter, no maximo, 100 caracteres.
              - PALAVRAS CHAVE: As palavras chave s�o palavras adicionais de no m�ximo 50 caracteres, sendo poss�vel
              adicionar no maximo 10 dessas. Tendo mais do que 10 palavras-chave, o programa acusar� erro.
                                                ||Exemplo:||
                           0001,YouTube,900,https://www.youtube.com/,youtube,videos,online
 -> Rodando o Programa:
   Primeiramente, devemos compilar o programa. Os comandos a seguir ser�o com base no compilador do terminal do linux:
   	gcc site.c avl.c cliente.c lista_encadeada_noCabeca_ordenada.c -o cliente.o
 	Depois de compilado (esperamos que com sucesso) basta executar. � preciso, no entanto, que o usu�rio tenha um
   arquivo googlebot.txt na mesma pasta que o programa, ou o programa iniciar� um novo vazio. 
   Para executar basta escrever no terminal:
      ./cliente.o
   e apertar enter. Iniciando o progrma.	
   No in�cio do progama as informa��es do googlebot.txt ser�o lidas, se qualquer informa��o 
   estiver errada, isto �, fora dos padr�es, uma mensagem de erro aparecer� e a informa��o com o erro n�o ser� inse-
   rida no programa. Ao colocar informa��es no arquivo, SIGA o padr�o estabelecido.

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
  	pois, caso o contr�rio, uma mensagem de erro ocorrer� e o site n�o ser� inserido. 
        <2)> Remover site: 
		Ao selecionar essa opcao o usu�rio poder�, dado um c�digo v�lido, retirar um dos sites da lista. Se
	o c�digo n�o for v�lido, uma mensagem de erro ocorrer� e o usuario ter� de tentar novamente. 
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
	em percurso em ordem. Se n�o houver nenhum site, nada ser� impresso. 
	<6> Buscar palavra:
		Nessa fun��o, ao selecionar uma palavra chave, ser�o impressas todos os sites que possuem essa chave assim
	como tamb�m todas as sugest�es. Sugest�es s�o aquelas que n�o possuem a palavra chave, mas que compartilham dos mesmos
	termos que sites que possuem ditas palavras apresentam. Os sites ser�o impressos em ordem de relev�ncia e n�o por
	possuir ou n�o a dita palavra. Se nenhum site possuir dita palavra chave, nada ser� impresso e o usu�rio voltar� ao menu.
	<7)> Sair:
		Selecionar essa op��o ir� finalizar o programa. Antes de finalizar, no entanto, o usu�rio tem a possibilidade de
	salvar todas as modifica��es feitas na �rvore e salva-las no googlebot.txt. Caso o "nao" seja selecionado, nenhuma modifica��o
	feita ser� salva para ser modificada depois. Depois de selecionar "sim" ou "nao" o programa ser� fechado e nada mais poder� ser	
	feito nele. 


	------------------------------------------------
	Metodos e estruturas utilizadas nesse trabalho:
	------------------------------------------------
		Nesse trabalho nos utilizamos de uma �rvore de busca bin�ria AVL com o intuito de atender aos requesitos 
	apresentados.
	Tal estrutura de dados nos permite utilizar esses programas em capacidades maiores e tamb�m de maneira mais eficiente
	do que, por exemplo, de uma lista. Isso ocorre pois em uma �rvore bin�ria, � poss�vel juntar dois dos aspectos mais
	importantes para a organiza��o de informa��o, o da capacidade do programa (sendo capaz de guardar muitas informa��es
	por alocar dinamicamente mem�ria) e o tamb�m da busca rapida (por sua natureza bin�ria, nos dando buscas O(logn)). 
		Os m�todos utilizados s�o os aprendidos em aula, tanto para a inser��o na �rvore, remo��o e o seu rebalanceamento.
	O utilizamos por motivos de seguran�a, pois esses eram c�digos j� utilizados antes e de confian�a em sua usabilidade.
	
	Para confeccionar o trabalho utilizamos alguns diferentes programas e compiladores. Dentre eles podemos citar o Geany,
	Sublime e tamb�m Dev c++, compila��es foram feitas tanto no compilador do Dev c++ como no compilador do gnu, j� imbutido
	no Linux.