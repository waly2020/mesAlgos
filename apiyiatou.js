const body = {
    username : "wafrt",
    password : "dkdkjbd",
    condition : "True",
    email : "djjbdugf@gmail.com"
}

fetch("https://yiatoutest.pythonanywhere.com/creation-2f416677-858f-796a-a221-690e5e4ae75a2f416677-858f-796a-a221-690e5e4ae75a",
{
    method : "POST",
    body : JSON.stringify(body),
    headers : {'Accept': 'application/json',
    'Content-Type': 'application/json'}
}).then(res =>{
    if(res.ok){
        console.log("utilisateur cree");
    }
    else{
        console.log("non cree");
    }
})