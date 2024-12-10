// Wait for the page to fully load
window.addEventListener("load", () => {
    const loadingScreen = document.getElementById("loading-screen");
    setTimeout(() => {
        loadingScreen.style.display = "none"; // Hide the loading screen
        document.body.classList.add("loaded"); // Allow scrolling
    }, 2000); // Adjust time (in milliseconds) as needed
});
