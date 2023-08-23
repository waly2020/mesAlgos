// http://127.0.0.1:8000/blog
fetch("http://127.0.0.1:8000/blog").then(res => res.json()).then(date =>{
    date.forEach(element => {
        console.log(`nom : ${element.title}\nslug : ${element.slug}\ncontent : ${element.content}\n`);
    });
})