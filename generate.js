const { execSync } = require('child_process');
const fs = require('fs');

function executeCommand(command, outputFile) {
  console.log(`Exécution de la commande...`);
  try {
    const start = Date.now();
    const stdout = execSync(command, { encoding: 'utf-8' });
    const duration = ((Date.now() - start) / 1000).toFixed(2);

    console.log(`Commande exécutée avec succès en ${duration}s`);
    console.log(`Filtrage des résultats pour écrire dans ${outputFile}...`);

    const outputStream = fs.createWriteStream(outputFile);
    stdout.split('\n').forEach((line) => {
		console.log(line);
      if (/^\d+$/.test(line)) {
        outputStream.write(line + '\n');
      }
    });
    outputStream.end();

    console.log(`Output filtré enregistré dans ${outputFile}`);
  } catch (error) {
    console.error(`Erreur lors de l'exécution de la commande : ${error.message}`);
  }
}

function generateRandomNumbers(count, min, max) {
  console.log(`Génération de ${count} nombres aléatoires entre ${min} et ${max}...`);
  const start = Date.now();

  const numbers = Array.from({ length: count }, () =>
    Math.floor(Math.random() * (max - min + 1)) + min
  );

  const duration = ((Date.now() - start) / 1000).toFixed(2);
  console.log(`Génération terminée en ${duration}s`);
  console.log("Lancer `node check.js` pour vérifier si les nombres sont dans l'ordre croissant.");

  return numbers.join(' ');
}

const randomNumbers = generateRandomNumbers(32, 100, 500);
const command = `./push_swap "${randomNumbers}"`;

executeCommand(command, 'output.txt');
