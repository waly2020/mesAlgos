const lowCase = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'];
const uppCase = ["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"];

/**
* @param {string} param_1
* @return {string}
*/
function alpha_mirror(param_1) {
    let p = "";
    for(let i = 0; i < param_1.length; i++){
        if(lowCase.includes(param_1[i])){
            p += lowCase[25 - lowCase.indexOf(param_1[i])];
        }else if(uppCase.includes(param_1[i])){
            p += uppCase[25 - uppCase.indexOf(param_1[i])];
        }else{
            p += param_1[i];
        }
    }
    console.log(p);
};

alpha_mirror("My horse is Amazing.")