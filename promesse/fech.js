let datas = [];

async function getData(){
    const r = await fetch("https://jsonplaceholder.typicode.com/posts");
    return r.json();
}
getData().then(d =>{
    console.log(d);
});

// console.log(datas);


function my_capitalize(str) {
    let splitted = str.split(' ')
    let result = ''
    for (let i = 0; i < splitted.length; i++) {
      result += splitted[i][0].toUpperCase() + splitted[i].slice(1) + ' '
    }
    console.log(result)
  }
my_capitalize('farrel baty kouima')