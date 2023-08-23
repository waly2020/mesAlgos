const codeSecret = `${Math.floor(Math.random() * 8000) + 1000}`;
let code = prompt("Bienvenue sur my mastermind\nQuel est le code secret ?\nnombre d'essai restan 10");
let tantative = 9;

if (code != codeSecret) {
    while (code != codeSecret && tantative > 0) {
        let lettreBien = 0;
        let lettreMal = 0;
        let goodIndex = [];
        for(let i = 0; i < codeSecret.length; i++){
            if(codeSecret[i] == code[i]){
                lettreBien++;
                goodIndex.push(i + 1);
            }else{
                lettreMal++;
            }
        }
        code = prompt(`nouvelle tentative...\nEssai restant ${tantative}\nLettre bien placé ${lettreBien}\nLettre mal placé ${lettreMal}\nDernier nombre entre : ${code}\nPosition de lettre bien placé ${goodIndex.join(" - ")}`);
        tantative--;
    }
    if(tantative <= 0){
        alert(`Vous n'avez pas reussi :(\nLe code secret etais ${codeSecret}`)
    }else{
        alert("Félicitation... :)")
    }
}else{
    alert("Réussi...");
}