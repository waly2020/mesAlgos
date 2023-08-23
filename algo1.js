let envelope = [
    {prix : 8,objectif : 20, nom : "terrain"},
    {prix : 34,objectif : 70, nom : "mariage"},
    {prix : 25,objectif : 50, nom : "A vendre"},
    {prix : 25,objectif : 50, nom : "tontine"},
    {prix : 25,objectif : 50, nom : "maladie"},
    // {prix : 98,objectif : 200, nom : "terrain"},
    // {prix : 98,objectif : 200, nom : "terrain"},
    // {prix : 98,objectif : 200, nom : "terrain"},
    // {prix : 98,objectif : 200, nom : "terrain"},
    // {prix : 98,objectif : 200, nom : "terrain"},
    // {prix : 98,objectif : 200, nom : "terrain"},
    // {prix : 10,objectif : 40, nom : "terrain"},
];

let taux = [];
let nom = [];

function getTaux(min,max){
    return (min/max) * 100;
}
 
let i = 1;
while (i < envelope.length && i < 5){
    taux.push(getTaux(envelope[envelope.length - i].prix,envelope[envelope.length - i].objectif)/100);
    nom.push(sliceLetter(envelope[envelope.length - i].nom,5));
    i++;
}

console.log(taux);
console.log(nom);
// console.log(taux.length);

// console.log(envelope[envelope.length - 2]);
/**
 * permet de supprimer une partie d'un mot
 * @param {string} word mot  coupe
 * @param {number} maxSlice nombre de lettre a garder
 */
function sliceLetter(word,maxSlice){
    if(word.length > maxSlice){
        return word.slice(0, maxSlice) + "...";
    }else{
        return word;
    }
}
// envelope.forEach(item =>{
//     console.log(sliceLetter(item.nom, 3) + "...");
// })
// console.log(sliceLetter("terrain"));