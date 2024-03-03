function validatePassword(){
    console.log("Function called");
    let pass = document.getElementById("password").value
    //let pattern = /^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[@$!%*?&])[A-Za-z\d@$!%*?&]{8,}$/;

    if (pass.length < 5 && /[a-z]/.test(pass) && /[A-Z]/.test)
    {
        alert('Password must have at least 5 characters');
       // document.getElementById("errorPasswordValidation").innerTest = "Password doesn't match criteria"
    }
}
