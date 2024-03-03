function validatePassword(){
    let pass = document.getElementById("password").value

    if (pass.length < 5 || !/[a-z]/.test(pass) || !/\d/.test(pass))
    {
        alert('Password must have at least 5 characters including letter and  digit');
        document.getElementById("password").value = "";
    }
}

function checkIfPasswordsAreMatching(){

    let password = document.getElementById("password").value;
    let confirmpassword = document.getElementById("confirmpassword").value;

    if (password != confirmpassword){
        alert('Passwords are not matching');
    }

}
function validateAmountOfShares(){
    let amount = document.getELementById("")
}
