const key = "7dff8c59c3153f57f1c78397f6c66e3a";
const ville = "libreville";
// fetch(`https://api.openweathermap.org/data/2.5/weather?q=${ville}&lang=fr&units=metric&appid=${key}`).then(res =>{
//     if(res.ok){
//         res.json().then(data =>{
//             console.log(data);
//         })
//     }else{
//         console.log(res);
//     }
//     // console.log("fech");
// }).catch(err =>{
//     console.log(err);
// })
// `https://api.openweathermap.org/data/2.5/forecast?lat=44.34&lon=10.99&appid=${key}`
fetch(`https://api.openweathermap.org/data/2.5/forecast?q=libreville,GA&appid=${key}`).then(res =>{
    if(res.ok){
        res.json().then(data =>{console.log(data)})
    }else{
        console.log(res.status);
    }
}).catch(err =>{
    console.log(err);
})
// console.log("meteo");