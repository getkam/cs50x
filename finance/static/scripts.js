function validatePassword(){
    let pass = document.getElementById("password").value

    if (pass.length < 5 || !/[a-z]/.test(pass) || !/[A-Z]/.test(pass) || /[@\.$!%*?&]/.test(pass) || !/d/.test(pass))
    {
        alert('Password must have at least 5 characters, small letter, capital letter, digit and special sign');
       // document.getElementById("errorPasswordValidation").innerTest = "Password doesn't match criteria"
    }
}

function checkIfPasswordsAreMatching(){

}
