-----------------------------------------
Alunos:
Henriqe Tadashi Tarzia n°:xxxxxxxx
Luiz Nome2 Nome3 Nome4 n°:xxxxxxxx
Lucas Xavier Ebling Pereira n°:10692183
-----------------------------------------

||GOOGLE BOT 2.0||


 ---------------------
 Instruções de uso:
 ---------------------

 -> Pré-Requisitos:
     Após a compilacao de "cliente.c" garanta que em seu computador tambem ha o arquivo "googlebot.txt" na mesma pasta
   que se encontra esse arquivo, nosso zip já traz uma pasta de tal nome com contudo para os testes necessários. O 
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
     ||A determinar|| No inicio do progama as informações de googlebot.txt serão lidas, se qualquer informacao 
   for errada, isto é, fora dos padroes, uma mensagem de erro aparecera e a informacao com o erro não será inse-
   rida no programa. Recomendamos que, ao colocar informações no arquivo, siga o padrão estabelecido.

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

 	A seguir serão apresentadas informações sobre cada uma das operações possíveis no programa:
   	<1)> Inserir site:
		Selecionando esta opção o usuário poderá inserir um novo site no programa, tal site será organizado
	em ordem de código com os outros sites já presentes. É necessário que as informações inseridas sejam válidas
  	pois, caso o contrário, uma mensagem de erro ocorrera e o site não será inserido. 
        <2)> Remover site: 
		Ao selecionar essa opcao o usuário poderá, dado um código valido, retirar um dos sites da lista. Se
	o código não for válido, uma mensagem de erro ocorrera e o usuario tera de tentar novamente. 
        <3)> Inserir chave:
    		Com essa opção o usuário pode, tendo um código válido, inserir uma nova palavra-chave no site escolhido.
	Da mesma maneira que os casos anteriores, se o código não existir uma mensagem de erro aparecerá e o usuário 
	terá de selecionar a opção novamente.
	<4)> Atualizar relevancia: 
		Com esse, dado um código válido, o usuário poderpá mudar a relevância de um site selecionado. Novamente,
	o código há de ser válido, se nâo for uma mensagem de erro aparecerá e o usuário tera de fazer o processo novamente.
	Igualmente, num caso de relevancia inválida, o usuáiro receberá uma mensagem de erro e terá de refazer o processo.
	<5)> Imprimir sites:
		Selecionando Imprimir sites o usuário imprimirá todos os sites presentes na árvore, os sites serâo impressos
	em percurso em ordem. 
	<6> Buscar palavra:
		Dada uma palavra-chave, essa opção irá imprimir (em ordem) todos os sites que possuem dita palavra chave. Caso a
	palavra-chave selecionada não esteja contida em nenhum site, nada será impresso. 
	<7)> Sair:
		Selecionar essa opção finalizará o programa, nada mais pode ser feito após selecionar essa opção. 





	LUCAS --->> O que fazer
      	-> Terminar o READ_ME
       	-> Fazer os displays de erro para minha funcao e outras; 