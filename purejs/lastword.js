/**
 * Renvoie le dernier d'une chaine de caractere
 * @param {string} param_1 chaine de carractere a verifier
 * @returns {string}
 */
function last_word(param_1){
    const regex = /^[a-zA-Z]$/;
    let newChaine = [];
    for(let i = param_1.length; i > 0; i--){
      if(regex.test(param_1[i])){
        let c = i;
        while (regex.test(param_1[c])){
          newChaine.unshift(param_1[c]);
          c--;
        }
        break;
      }
    }
    return newChaine.join("");
}