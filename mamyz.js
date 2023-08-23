// const data = {
//     name : "inconnu1800",
//     email : "inconnu92581@gmail.com",
//     password : "987654321"
// }
// // console.log(data);
// fetch("https://mamyz-backend.vercel.app/users/register",{
  
//   method : "POST",
//   body : JSON.stringify(data),
//   headers : {'Accept': 'application/json','Content-Type': 'application/json'}

// }).then(response =>{
//   // console.log('Statut de la requete : ',response.status);
//   // console.log('Requete ok ? ',response.ok);
//   // console.log(response);
//   // console.log(response.headers);
//   // console.log(response.body);
//   // console.log(response.json());
//   if(response.ok){
//     response.json().then(data => {
//       console.log(data);
//     }) 
//   }else{
//     console.log(response);
//   }
// }).catch(err =>{
//   console.log('erreur : ',err);
// })
const data = {
    "title" : "teste comme sa",
    "montantActuel" : "3000",
    "panalite" : "5",
    "dateEcheance" : "123476435",
    "montantAtteindre" : "30000",
    "userId" : "8"
}
fetch("https://mamyz-backend.vercel.app/api/v1/envelop",{
  method : "POST",
  body : data,
  headers : {'Accept': 'application/json','Content-Type': 'application/json'}
}).then(response =>{
  console.log("Statut : ",response.status);
  console.log("Ok ? ", response.ok);
}) 