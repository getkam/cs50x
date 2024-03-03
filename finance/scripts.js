function validatePassword(event){
    let pass = event.target.innerText;
    let pattern = /^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[@$!%*?&])[A-Za-z\d@$!%*?&]{8,}$/;

    if (!pattern.text(pass))
    {
        alert("Password doesn't match criteria");
    }
}
