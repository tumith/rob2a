// Get the Sidebar
const mySidebar = document.getElementById("mySidebar");
// Get the DIV with overlay effect
const overlayBg = document.getElementById("myOverlay");
// Get the open button
const openBtn = document.getElementById("w3_open_btn");
// Get the close button
const closeBtns = document.getElementsByClassName("w3_close_btn");

// Toggle between showing and hiding the sidebar, and add overlay effect
openBtn.addEventListener("click", () => {
    if (mySidebar.style.display === "block") {
        mySidebar.style.display = "none";
        overlayBg.style.display = "none";
    } else {
        mySidebar.style.display = "block";
        overlayBg.style.display = "block";
    }
});

// Close the sidebar with the close buttons
for (let i = 0; i < closeBtns.length; i++) {
    console.log(i);
    
    closeBtns[i].addEventListener("click", () => {
        mySidebar.style.display = "none";
        overlayBg.style.display = "none";
    });
}