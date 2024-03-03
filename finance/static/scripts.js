function validatePassword(){
    let pass = document.getElementById("password").value

    if (pass.length < 5 || !/[A-z]/.test(pass) || !/[@\.$!%*?&]/.test(pass) || !/d/.test(pass))
    {
        alert('Password must have at least 5 characters, letter, digit and special sign');
        document.getElementById("password").value = "";
       // document.getElementById("errorPasswordValidation").innerTest = "Password doesn't match criteria"
    }
}

function checkIfPasswordsAreMatching(){

    let password = document.getElementById("password").value;
    let confirmpassword = document.getElementById("confirmpassword").value;

    if (password != confirmpassword){
        alert('Passwords are not matching');
    }

}
