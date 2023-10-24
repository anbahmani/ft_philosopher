[![en](https://img.shields.io/badge/language-en-red.svg)](https://github.com/anbahmani/ft_philosopher/blob/master/README.md)

## Table des Matières
1. [Introduction](#introduction)
2. [Description du Projet](#description-du-projet)
3. [Détails de la Simulation](#détails-de-la-simulation)
4. [Objectifs](#objectifs)
5. [Défis](#défis)
6. [Lancer le programme](#lancer-le-programme)

## Introduction
"Les Philosophes qui dînent" est un problème classique de synchronisation qui met en perspective les défis pour assurer une gestion appropriée des ressources, la prévention des interblocages et la synchronisation des processus dans un environnement multitâche. Ce projet simule les conditions et les paramètres de ce concept renommé de manière visuelle et interactive.

## Description du Projet
Dans cette simulation, nous explorons un scénario impliquant des philosophes avec trois activités de vie simples : manger, réfléchir et dormir. Le cadre est une table ronde avec un repas copieux au centre, entouré de philosophes silencieux qui ne doivent jamais communiquer. Le défi est de simuler leurs actions tout en empêchant tout philosophe de mourir de faim, démontrant le multitâche et la synchronisation en temps réel.

## Détails de la Simulation
- Philosophes : Chaque philosophe représente un fil (thread) ou un processus indépendant. Leurs actions sont cycliques et continues, passant d'un état à un autre.
- Ressources : Les fourchettes représentent des ressources limitées, essentielles pour l'activité principale des philosophes : manger. Chaque philosophe a besoin de deux fourchettes pour manger.
- États : Chaque philosophe passe par trois états :
	- Manger : Le philosophe prend les fourchettes de leur gauche et de leur droite, mange pendant un certain temps, puis repose les fourchettes.
	- Dormir : Après avoir mangé, le philosophe va dormir, ne nécessitant aucune ressource.
	- Réfléchir : Après le sommeil, le philosophe s'engage dans la réflexion, toujours indépendant des ressources.
- Cycle de vie : Le cycle continue indéfiniment jusqu'à la conclusion de la simulation, généralement lors de l'événement malheureux de la mort d'un philosophe due à la faim.

## Objectifs
- Pas de Famine : L'objectif principal est de s'assurer qu'aucun philosophe ne meure de faim, c'est-à-dire que chaque philosophe a une chance équitable de manger avant de manquer de temps.
- Prévention des Interblocages : La simulation doit prévenir les interblocages du système, en s'assurant que la condition d'attente circulaire ne se produise pas.
- Gestion des Ressources : Gestion appropriée des ressources (fourchettes), en s'assurant qu'elles sont disponibles pour chaque tour de philosophe pour manger.
- Synchronisation : Mettre en œuvre des mécanismes de synchronisation pour gérer efficacement les actions des philosophes et les demandes de ressources.

## Défis
- Règle du Silence : Les philosophes ne communiquent pas, rendant impossible une action préventive basée sur l'état d'un autre.
- Ignorance de l'État des Autres : Les philosophes ne peuvent pas déterminer si d'autres sont sur le point de mourir de faim, mettant l'accent sur la gestion individuelle des ressources.
- Survie : Il va sans dire que le défi ultime est de garder tous les philosophes en vie tout au long de la simulation.

## Lancer le programme

```
  git clone git@github.com:anbahmani/philosopher.git
  cd philosopher ; make ; ./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat] (optional)
```


Ce projet est un exercice pratique pour comprendre et mettre en œuvre les principes du multitâche, les stratégies d'allocation des ressources et les mécanismes de synchronisation dans un environnement contraint. Il nécessite une observation attentive, une prise de décision rapide et des compétences de résolution de problèmes en temps réel pour maintenir un équilibre dans le monde des philosophes.