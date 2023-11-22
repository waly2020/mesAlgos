/**
 * 
 * @param {[number]} param_1 
 * @param {number} param_2 
 * @returns {number}
 */
function find_pivot(param_1, param_2) {
    let index = -1;
    for(let i = 0; i < param_2; i++){
        if(i > 0 && i < param_2){
            let leftTab = param_1.filter((_,index,__) => index >= 0 && index <= i - 1);
            let rightTab = param_1.filter((_,index,__) => index >= i + 1 && index < param_2);
            let resultLeft = leftTab.reduce((a,b) => a + b);
            let resultRight = rightTab.reduce((a,b) => a + b,0);
            if(resultLeft == resultRight){
                index = i;
                break;
            }
        }
    }
    return index;
}
console.log(find_pivot([-5, 10, 2, 5], 4));