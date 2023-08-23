let datas = [];

async function getData(){
    const r = await fetch("https://jsonplaceholder.typicode.com/posts");
    return r.json();
}
getData().then(d =>{
    console.log(d);
});

// console.log(datas);