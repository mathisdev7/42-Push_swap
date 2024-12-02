const fs = require('fs');

function checkIfSorted(filePath) {
  console.log(`Lecture du fichier : ${filePath}...`);
  try {
    const start = Date.now();

    const data = fs.readFileSync(filePath, 'utf-8');
    console.log("Fichier lu avec succès.");

    const numbers = data.trim().split('\n').map(Number);
    console.log(`Nombre total de lignes : ${numbers.length}`);

    for (let i = 1; i < numbers.length; i++) {
      if (numbers[i] < numbers[i - 1]) {
        console.log(`Les nombres ne sont pas dans l'ordre croissant : ${numbers[i - 1]} > ${numbers[i]} (index ${i - 1} et ${i})`);
        return;
      }
    }

    const duration = ((Date.now() - start) / 1000).toFixed(2);
    console.log(`Les nombres sont dans l'ordre croissant. Vérification terminée en ${duration}s.`);
  } catch (error) {
    console.error("Erreur lors de la lecture du fichier :", error.message);
  }
}

checkIfSorted('output.txt');
