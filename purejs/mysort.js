const tab = [8,7,6,5,9];
function mysort(array){

    // let sortArray = [];
    // let index = 0;
    // for (let i = 0; i < array.length; i++) {
    //     let num = array[i];
    //     if(array[i] !== array[i + 1]){
    //         // console.log("nom double",array[i] + " : " + i);
    //         sortArray[index] = array[i];
    //         index++;
    //     }
    // }
    console.log(sortArray);
    for(let b = 0; b < (sortArray.length - 1); b++){
        if(sortArray[b] > sortArray[b + 1]){
            console.log(`${sortArray[b]} > ${sortArray[b + 1]} : plus grand que et b = ${b}`);
            for(let c = 0; c < (sortArray.length - 1); c++){
                console.log(`${sortArray[c]} : ${sortArray[c + 1]}`);
                if(sortArray[c] < sortArray[c + 1]){
                    console.log("non sort (inf)");
                    return;
                }
            }
            console.log("en ordre (inf)");
            return;
            
        }
        else if(sortArray[b] <= sortArray[b + 1]){
            console.log(`${sortArray[b]} < ${sortArray[b + 1]} : plus petit que et b = ${b}`);
            for(let c = 0; c < sortArray.length; c++){
                if(sortArray[c] > sortArray[c + 1]){
                    console.log("non sort");
                    return;
                }
            }
            console.log("en ordre");
            return;
            
        }
    }
    
}
mysort(tab);