document.addEventListener("DOMContentLoaded", function () {
    function fire() {
        confetti({
            particleCount: 200,
            spread: 100,
            origin: { y: 0.9, x: 0.2 },
        });
        confetti({
            particleCount: 200,
            spread: 100,
            origin: { y: 0.9, x: 0.5 },
        });
        confetti({
            particleCount: 200,
            spread: 100,
            origin: { y: 0.9, x: 0.8 },
        });
    }

    const footer = document.querySelector("footer");
    let confettiFired = false;
    const confettiBtn = document.getElementById("confetti-again-btn");
    if (confettiBtn) confettiBtn.classList.remove("revealed"); // Hide on load

    if (footer) {
        const observer = new IntersectionObserver(
            entries => {
                entries.forEach(entry => {
                    if (entry.isIntersecting && !confettiFired) {
                        confettiFired = true;
                        fire();
                        // Reveal the button after 2 seconds
                        setTimeout(() => {
                            if (confettiBtn) confettiBtn.classList.add("revealed");
                        }, 2000);
                    }
                });
            },
            { threshold: 0.1 },
        );
        observer.observe(footer);
    }
    // Optionally, expose fire globally for button
    window.fire = fire;
});
