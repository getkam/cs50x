function validatePassword(){
    console.log("Function called");
    let pass = document.getElementById("password").value
    //let pattern = /^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[@$!%*?&])[A-Za-z\d@$!%*?&]{8,}$/;

    if (pass.lenght < 5)
    {
        alert('Password must have at least 5 characters')
       // document.getElementById("errorPasswordValidation").innerTest = "Password doesn't match criteria"
    }
}
