#331CA Grigorie Ruxandra


##Detalii implementare
------------------------

1) Elemente decorative
------------------------

	* Stufaris:
	-----------
		a) tulpina + capul stufarisului - cuburi scalate, pe care le-am creeat manual
		b) frunze - dreptunghiuri (creeate manual), scalate si rotite pe cele 3 axe: OX, OY, OZ.
		
		* geometrie si texturare
			- pentru texturarea cubului am dedus coordonatele de texturare

			- am creeat manual o mesha pentru un dreptunghi, pe care am utilizat-o in creearea stufarisului 
			- pentru texturarea frunzelor am dedus coordonatele de texturare pentru dreptunghiuri
	
		* amplasare in scena
			- am salvat parametrii de scalare, translatare si rotatie pe cele 3 axe ale 
			componentelor stufarisului in vectori

			- la randare, translatez stufarisul (componentele sale) cu diverse offset-uri,
			pentru a le amplasa in pozitii diferite din scena 

	* Ciuperci:
	------------
		- atat piciorul cat si capul ciupercii sunt alcatuite din cuburi (creeate manual) scalate, peste care am
		aplicat o textura
	
		- pentru texturarea cubului am dedus coordonatele de texturare
	
		- amplasez in scena ciupercile in mod asemenator cu stufarisul 

	* Nuferi
	---------
		- petala unui nufar este un cerc scalat (ingustat). 
		- floarea este alcatuita dintr-o succesiune de petale 


2) Platforme
--------------

	** Pentru a se potrivi cu tematica jocului, am modificat forma platformelor, pentru a fi frunze de nuferi.
	** Frunzele de nuferi sunt cercuri (creeate manual), peste care am aplicat o textura (cu coordonate de texturare deduse manual)

	** Am pastrat logica power-up-urilor oferite de platforme, cu modificarea ca am interschimbat culoarea albastru cu cea verde. 

3) Obstacole
-------------

	** Obstacolele sunt amplasate pe nuferi, si sunt sub forma unei flori de nufar. Aceasta a fost creeata dintr-o succesiune de cercuri scalate.
	** Texturarea s-a facut in mod asemanator cu nuferii, cu precizarea ca am aplicat textura unei petale de flori.
	** La coliziunea cu acestea, jucatorul pierde o viata.


4) Elemente colectabile
------------------------

	** Ca obiecte colectabile am introdus felii de paine. Exista 2 tipuri de paine: normala, care confera jucatorului +50 de p, si
	paine mucegaita, care ofera jucatorului -50 de p.

	** Painea este formata dintr-un cub scalat, peste care am aplicat o textura de paine. 
	
	** Ca animatie, am imprimat colectabilelor o miscare de rotatie 


5) Iluminarea 
--------------

	** Lumina de tip spot: am introdus o lumina de tip spot sub forma unui licurici (sfera), care este amplasata in varful stufarisului. Pentru 
	coloararea luminii, pasez la shader un vector de culori. 

	** Lumina punctiforma: am introdus o lumina de tip punctiforma sub forma unei luni pe cer. Luna este o sfera peste care am aplicat o textura.



6) Bonusuri
-------------

	* Schimbarea geometriei platformelor, specifică stilului vizual ales - nuferi
	* Fundal - cer instelat 