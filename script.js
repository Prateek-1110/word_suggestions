document.addEventListener("DOMContentLoaded", function () {
    const searchBox = document.getElementById("search");
    const suggestionBox = document.getElementById("suggestions");

    searchBox.addEventListener("input", async function () {
        let query = searchBox.value.trim();
        console.log("User Input:", query); 
//clearing suggestions
        if (query === "") {
            suggestionBox.innerHTML = ""; 
            return;
        }

        try {
            let response = await fetch(`http://127.0.0.1:5000/suggest?query=${query}`);
            console.log("Fetch Response:", response); 

            if (!response.ok) {
                throw new Error("Failed to fetch suggestions");
            }

            let suggestions = await response.json();
            console.log("Suggestions:", suggestions); 

            suggestionBox.innerHTML = ""; 

            if (suggestions.length === 0) {
                suggestionBox.innerHTML = "<li>No suggestions found</li>";
                return;
            }

//printing suggestions
            suggestions.forEach(word => {
                let li = document.createElement("li");
                li.textContent = word;
                li.addEventListener("click", function () {
                    searchBox.value = word; 
                    suggestionBox.innerHTML = ""; 
                });
                suggestionBox.appendChild(li);
            });

        } catch (error) {
            console.error("Error fetching suggestions:", error);
        }
    });
});
