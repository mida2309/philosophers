# Philosophers - I never thought philosophy would be so deadly

*This project has been created as part of the 42 curriculum by mida*

---

## English Version

### Description
Philosophers is a project focused on the basics of threading a process. It explores the challenges of concurrent programming by simulating the "Dining Philosophers" problem, where multiple entities must share limited resources without creating conflicts or system failures.

### Features
- **Multi-threading**: Creation and management of multiple threads within a single process.
- **Synchronization**: Use of mutexes to protect shared data and prevent race conditions.
- **Monitoring**: Implementation of a monitoring system to track the status of each thread in real-time.
- **Resource Management**: Efficient handling of shared resources to avoid deadlocks (mutual blocking).
- **Time Precision**: Accurate time management to ensure the simulation respects strict constraints.

### Technical Requirements
- Language: C.
- Strict compliance with the 42 Norm.
- No memory leaks or data races allowed.
- Efficient use of system calls: pthread_create, pthread_join, pthread_mutex_init/lock/unlock.

### Resources and AI Usage
In accordance with 42 curriculum guidelines, AI tools were utilized for initial structural design and debugging concurrency issues. Every AI-generated suggestion was reviewed, tested, and verified to ensure full technical understanding of thread synchronization and mutex logic.

********************************************************************************

## Version Française

### Description
Philosophers est un projet axé sur les bases du multi-threading. Il explore les défis de la programmation concurrente en simulant le problème du "Dîner des philosophes", où plusieurs entités doivent partager des ressources limitées sans créer de conflits ou de défaillance du système.

### Fonctionnalités
- **Multi-threading** : Création et gestion de plusieurs threads au sein d'un même processus.
- **Synchronisation** : Utilisation de mutex pour protéger les données partagées et prévenir les "race conditions".
- **Surveillance** : Mise en place d'un système de monitoring pour suivre l'état de chaque thread en temps réel.
- **Gestion des ressources** : Manipulation efficace des ressources partagées pour éviter les "deadlocks" (blocages mutuels).
- **Précision temporelle** : Gestion précise du temps pour garantir que la simulation respecte des contraintes strictes.

### Exigences Techniques
- Langage : C.
- Respect strict de la Norme 42.
- Absence totale de fuites mémoire ou de "data races".
- Utilisation efficace des appels système : pthread_create, pthread_join, pthread_mutex_init/lock/unlock.

### Ressources et Utilisation de l'IA
Conformément aux directives du cursus 42, des outils d'IA ont été utilisés pour la conception structurelle initiale et le débogage des problèmes de concurrence. Chaque suggestion a été revue, testée et vérifiée afin de garantir une compréhension technique totale de la synchronisation des threads et de la logique des mutex.
