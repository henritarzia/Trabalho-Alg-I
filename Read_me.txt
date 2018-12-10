-----------------------------------------
Alunos:
Henrique Tadashi Tarzia n°:10692210
Luís Felipe Riveiro Chaves n°:10801221
Lucas Xavier Ebling Pereira n°:10692183
-----------------------------------------

||GOOGLE BOT 2.0||


 ---------------------
 Instruções de uso:
 ---------------------

 -> Pré-Requisitos:
     Após a compilacao de "cliente.c", garanta que em seu computador também há o arquivo "googlebot.txt" na mesma pasta
   que se encontra esse arquivo, nosso zip já traz uma pasta de tal nome com tudo necessário para os testes. O 
   conteúdo dessa pasta, pode ser mudado desde que ela mantenha o padrão nela presente.
                                              ||O padrão:||
              O texto sera sempré apresentado no padrao CSV (comma separated values) da seguinte maneira:
                                ||código,nome,relevância,link,palavras-chave||
              - CÓDIGO: É um código numérico de quatro dígitos entre 0000 e 1000, qualquer valor acima será
              mostrado como um erro e deve ser modificado.
              - NOME: O nome é um conjunto de no máximo 50 caracteres que devem ser, preferencialmente, do modelo ASCII.
	      Outros tipos de carcteres são permitidos, mas devido às diferenças entre computadores, pode ocorrer problemas de inteligibilidade.
              - RELEVÂNCIA: Valor numérico entre 0000 e 1000 (valores acima serão gerarão erro e deverão ser adaptados).
              - LINK: O link é o link do site, podendo ter, no maximo, 100 caracteres.
              - PALAVRAS CHAVE: As palavras chave são palavras adicionais de no máximo 50 caracteres, sendo possível
              adicionar no maximo 10 dessas. Tendo mais do que 10 palavras-chave, o programa acusará erro.
                                                ||Exemplo:||
                           0001,YouTube,900,https://www.youtube.com/,youtube,videos,online
 -> Rodando o Programa:
   Primeiramente, devemos compilar o programa. Os comandos a seguir serão com base no compilador do terminal do linux:
   	gcc site.c avl.c cliente.c lista_encadeada_noCabeca_ordenada.c -o cliente.o
 	Depois de compilado (esperamos que com sucesso) basta executar. É preciso, no entanto, que o usuário tenha um
   arquivo googlebot.txt na mesma pasta que o programa, ou o programa iniciará um novo vazio. 
   Para executar basta escrever no terminal:
      ./cliente.o
   e apertar enter. Iniciando o progrma.	
   No início do progama as informações do googlebot.txt serão lidas, se qualquer informação 
   estiver errada, isto é, fora dos padrões, uma mensagem de erro aparecerá e a informação com o erro não será inse-
   rida no programa. Ao colocar informações no arquivo, SIGA o padrão estabelecido.

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
  	pois, caso o contrário, uma mensagem de erro ocorrerá e o site não será inserido. 
        <2)> Remover site: 
		Ao selecionar essa opcao o usuário poderá, dado um código válido, retirar um dos sites da lista. Se
	o código não for válido, uma mensagem de erro ocorrerá e o usuario terá de tentar novamente. 
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
	em percurso em ordem. Se não houver nenhum site, nada será impresso. 
	<6> Buscar palavra:
		Nessa função, ao selecionar uma palavra chave, serão impressas todos os sites que possuem essa chave assim
	como também todas as sugestões. Sugestões são aquelas que não possuem a palavra chave, mas que compartilham dos mesmos
	termos que sites que possuem ditas palavras apresentam. Os sites serão impressos em ordem de relevância e não por
	possuir ou não a dita palavra. Se nenhum site possuir dita palavra chave, nada será impresso e o usuário voltará ao menu.
	<7)> Sair:
		Selecionar essa opção irá finalizar o programa. Antes de finalizar, no entanto, o usuário tem a possibilidade de
	salvar todas as modificações feitas na árvore e salva-las no googlebot.txt. Caso o "nao" seja selecionado, nenhuma modificação
	feita será salva para ser modificada depois. Depois de selecionar "sim" ou "nao" o programa será fechado e nada mais poderá ser	
	feito nele. 


	------------------------------------------------
	Metodos e estruturas utilizadas nesse trabalho:
	------------------------------------------------
		Nesse trabalho nos utilizamos de uma árvore de busca binária AVL com o intuito de atender aos requesitos 
	apresentados.
	Tal estrutura de dados nos permite utilizar esses programas em capacidades maiores e também de maneira mais eficiente
	do que, por exemplo, de uma lista. Isso ocorre pois em uma árvore binária, é possível juntar dois dos aspectos mais
	importantes para a organização de informação, o da capacidade do programa (sendo capaz de guardar muitas informações
	por alocar dinamicamente memória) e o também da busca rapida (por sua natureza binária, nos dando buscas O(logn)). 
		Os métodos utilizados são os aprendidos em aula, tanto para a inserção na árvore, remoção e o seu rebalanceamento.
	O utilizamos por motivos de segurança, pois esses eram códigos já utilizados antes e de confiança em sua usabilidade.
	
	Para confeccionar o trabalho utilizamos alguns diferentes programas e compiladores. Dentre eles podemos citar o Geany,
	Sublime e também Dev c++, compilações foram feitas tanto no compilador do Dev c++ como no compilador do gnu, já imbutido
	no Linux.