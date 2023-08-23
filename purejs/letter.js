/**
 * Cherche une aiguille dans une bote de foin.
 * @param {string} str1 
 * @param {string} str2 
 */
function letters(str1,str2){
    let strTest = "";
    let newStr = "";
    for(let i = 0; i < str1.length; i++){
        if(str1[i] == str2[0]){
            for(let b = 0; b < str2.length; b++){
                strTest += str1[i + b];
            }
        }
        if(str2 == strTest){
            for (let c = 0; c < (str1.length - i); c++){
                newStr += str1[c + i];
            }
            break;
        }else{
            strTest = "";
        }
    }
    console.log(strTest);
    console.log(newStr);
}


letters("abe2cdeabe123","be1");