
const Create = () => {
    // Initialisation des états d'erreur et de chargement de la page
    const [erreur, SetErreur] = useState(false);
    const [top, SetTop] = useState(false);

    const [check, setCheck] = useState(false);
    const userName = useRef("");
    const lastName = useRef("");
    console.log(lastName.current.value);
    const password = useRef("");
    const genre = useRef("");
    const numero = useRef("");

    const handleForm = async (e) => { // déclare une fonction asynchrone qui sera exécutée lors de la soumission du formulaire

        e.preventDefault(); // empêche la soumission du formulaire de se produire par défaut

        // const data = new FormData(); // crée un nouvel objet FormData qui stockera les données du formulaire
        // data.append("username", userName.current.value); // ajoute la valeur du champ "username" du formulaire à l'objet FormData
        // data.append("fullname", lastName.current.value); // ajoute la valeur du champ "email" du formulaire à l'objet FormData
        // data.append("genre", genre.current.value); // ajoute la valeur du champ "password" du formulaire à l'objet FormData
        // data.append("phone", numero.current.value); // ajoute la valeur du champ "password" du formulaire à l'objet FormData
        // data.append("password", password.current.value); // ajoute la valeur du champ "password" du formulaire à l'objet FormData
        // data.append("condition", conditions.current.value); // ajoute la valeur du champ "password" du formulaire à l'objet FormData
        // data.append("teste","valeur de teste");
        const data = {
            username : userName.current.value,
            // fullname : lastName.current.value,
            // phone : numero.current.value,
            // genre : genre.current.value,
            password : password.current.value,
            condition : `${check}`,
            email : "abc@gmail.com",
            // home_address_acheteurs : "123 main St",
            // birthdate_acheteurs : "1999-01-02"
        }
        SetTop(true); // met à jour l'état de la variable "Top" à true

        let response = await fetch( // envoie une requête POST à l'endpoint de création de compte utilisateur de l'API
        "https://yiatoutest.pythonanywhere.com/creation-2f416677-858f-796a-a221-690e5e4ae75a2f416677-858f-796a-a221-690e5e4ae75a",
        {
            method: "POST",
            body: JSON.stringify(data),
            // headers : {'Content-Type' : "application/json"}
        }
        );
        let dataUser = await response.json(); // récupère les données de réponse sous forme d'objet JSON

        if (response.ok) { // si la réponse est valide (statut 200-299)
        Cookies.set( // stocke le jeton d'accès dans un cookie nommé "2f416677-858f-796a-a221-690e5e4ae75a-token"
            "2f416677-858f-796a-a221-690e5e4ae75a-token",
            JSON.stringify(dataUser),
            { expires: 7, path: "/" }
        );

        Cookies.set( // stocke le nom d'utilisateur dans un cookie nommé "2f416677-858f-796a-a221-690e5e4ae75a-Cooktoken"
            "2f416677-858f-796a-a221-690e5e4ae75a-Cooktoken",
            JSON.stringify({ nom: userName.current.value }),
            { expires: 7, path: "/" }
        );
        console.log(response);
        window.location.reload(); // recharge la page après avoir stocké les cookies
        } else { // si la réponse n'est pas valide
        
        SetErreur(dataUser); // met à jour l'état de la variable "Erreur" avec les données de réponse de l'API
        SetTop(false); // met à jour l'état de la variable "Top" à false
        console.log("reponse");
        console.log(response.body);
        console.log("data");
        console.log(data);
        console.log("user name");
        console.log(lastName.current.value);
        }
    };
    

    return (
        <form onSubmit={handleForm} className='form create'>
            <div className="inputs">
            <div className="input">
                    <p className="input-desc">Nom</p>
                    <input ref={userName} onChange={txt => {console.log(userName.current.value);}} type="text" name="prenom" id='prenom' placeholder='Doe' required={true} />
                </div>
                <div className="input">
                    <p className="input-desc">Prenom</p>
                    <input ref={lastName} type="text" name="prenom" id='prenom' placeholder='Doe' required={true} />
                </div>
                <div className="input">
                    <p className="input-desc">Civilité</p>
                    <select ref={genre} name="civiliter" id="civiliter" required={true}>
                        <option value="homme">Monsieur</option>
                        <option value="femme">Madame</option>
                    </select>
                </div>
                <div className="input">
                    <p className="input-desc">Numero de telephone</p>
                    <input ref={numero} type="tel" name="numero" id="numero" placeholder='074000000' required={true} />
                </div>
                <div className="input">
                    <p className="input-desc">Mot de passe</p>
                    <input ref={password} type="password" name="password" id="password" required={true} />
                </div>
                <p className='link-conditions'>
                    <Link to="/condition-utilisation/log/create">Lire les conditions d'utilisations</Link>
                </p>
                <div className="input-label">
                    <input type="checkbox" name="conditions" id="conditions" checked={check} onChange={() => {
                        setCheck(!check);
                    }} />
                    <label htmlFor="conditions">J'ai lu les conditions d'utilisations</label>
                </div>
            </div>
            <div className="button-submit">
                <button type={check ? "submit" : "button"} className={check ? "checked" : ""}>Je cree mon compte</button>
            </div>
            <p className='link'>Vous avez deja un compte ? <Link to="/log/login">connectez-vous !</Link></p>
        </form>
    );
};