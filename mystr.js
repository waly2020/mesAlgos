/**
 * 
 * @param {string} param_1 
 * @param {string} param_2 
 */
function my_strrchr(param_1, param_2) {
  if(param_1.includes(param_2)){
    let id = param_1.lastIndexOf(param_2);
    if(id < (param_1.length - 1)){
        
        console.log(`${param_1[id]}${param_1[id + 1]}`);
    }else{
        console.log(param_1[id]);
    }
  }else{
    return null;
  }
};
my_strrchr("aabbc","a");
my_strrchr("abc","c");
my_strrchr("abc","b");
my_strrchr("abc","d");