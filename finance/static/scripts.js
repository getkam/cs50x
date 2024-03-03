function validatePassword(){
    console.log("Function called");
    let pass = document.getElementById("password").value
    let pattern = /^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[@$!%*?&])[A-Za-z\d@$!%*?&]{8,}$/;

    if (!pattern.test(pass))
    {
        alert("Password doesn't match criteria");
    }
}
