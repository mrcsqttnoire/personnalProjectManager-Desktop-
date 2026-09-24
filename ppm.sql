-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1
-- Généré le : lun. 06 oct. 2025 à 00:58
-- Version du serveur : 10.4.28-MariaDB
-- Version de PHP : 8.2.4

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `ppm`
--

-- --------------------------------------------------------

--
-- Structure de la table `priorite`
--

CREATE TABLE `priorite` (
  `Code_p` int(3) NOT NULL,
  `Type_p` enum('Urgent','Important','Normal','') NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Déchargement des données de la table `priorite`
--

INSERT INTO `priorite` (`Code_p`, `Type_p`) VALUES
(1, 'Normal'),
(2, 'Important'),
(3, 'Urgent');

-- --------------------------------------------------------

--
-- Structure de la table `projet`
--

CREATE TABLE `projet` (
  `Id_p` int(11) NOT NULL,
  `titre_p` varchar(200) NOT NULL,
  `description_p` text NOT NULL,
  `date_debut` date NOT NULL,
  `date_fin` date DEFAULT NULL,
  `Id_priorite` int(3) NOT NULL DEFAULT 1,
  `statut_p` enum('en_cours','termine','pause','annule') NOT NULL DEFAULT 'en_cours',
  `categori_p` varchar(50) NOT NULL DEFAULT 'personnel',
  `note_p` text NOT NULL,
  `id_ut` int(11) NOT NULL,
  `date_creation` timestamp NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Déchargement des données de la table `projet`
--

INSERT INTO `projet` (`Id_p`, `titre_p`, `description_p`, `date_debut`, `date_fin`, `Id_priorite`, `statut_p`, `categori_p`, `note_p`, `id_ut`, `date_creation`) VALUES
(1, 'Apprendre PHP', 'Lorem ipsum dolor sit amet consectetur adipisicing elit. Cupiditate nam facere voluptas similique ipsam tenetur obcaecati cum, delectus aliquid officia adipisci aut voluptatibus assumenda quis quia sapiente dolor esse explicabo.', '2025-07-02', '2025-07-13', 1, 'en_cours', 'educatif', 'objectif: Maitriser CRUD et structure MVC', 3, '2025-05-15 04:50:23'),
(5, 'React', 'Lorem ipsum dolor sit, amet consectetur adipisicing elit. Veniam, eos debitis? Vero provident consequuntur tempore nihil libero harum ipsa. Deleniti dicta, nihil, aliquam odit ullam porro maxime, quaerat numquam a odio ad soluta? Natus quo libero cumque beatae hic modi.', '2025-08-11', '2025-09-07', 1, 'en_cours', 'Educatif', 'Lorem ipsum dolor sit, amet consectetur adipisicing elit.', 3, '2025-06-02 17:12:54'),
(12, 'C++', 'Lorem ipsum dolor sit amet consectetur adipisicing elit. Cupiditate nam facere voluptas similique ipsam tenetur obcaecati cum, delectus aliquid officia adipisci aut voluptatibus assumenda quis quia sapiente dolor esse explicabo.', '2025-08-03', '0000-00-00', 2, 'termine', 'educatif', 'Lorem ipsum dolor sit amet consectetur adipisicing el', 3, '2025-06-19 17:32:47'),
(13, 'Teste Rakoto', 'Lorem ipsum dolor sit amet consectetur adipisicing elit. Ipsa sequi nam vitae, magni enim magnam natus, veritatis doloremque debitis ratione at voluptatibus facilis recusandae officia consectetur architecto quia quos consequatur!', '2025-08-01', '0000-00-00', 1, 'en_cours', 'creatif', 'Lorem ipsum dolor sit amet consectetur adipisicing elit. Ipsa sequi nam vitae, magni enim magnam natus, veritatis doloremque debitis ratione at voluptatibus facilis recusandae officia consectetur architecto quia quos consequatur!', 4, '2025-08-04 04:24:03'),
(15, 'Python', 'Lorem ipsum dolor sit amet consectetur adipisicing elit. Cupiditate nam facere voluptas similique ipsam tenetur obcaecati cum, delectus aliquid officia adipisci aut voluptatibus assumenda quis quia sapiente dolor esse explicabo.', '2025-07-17', '0000-00-00', 3, 'termine', 'educatif', '', 3, '2025-07-06 09:34:03'),
(46, 'Apprendre C++', 'Lorem ipsum dolor sit amet consectetur adipisicing elit. Nemo aliquam in itaque officiis sequi commodi qui dolore, accusantium doloribus ut, earum animi est modi odit a eius cumque beatae molestias. Molestiae, a, velit ad delectus quo nemo repellat, nam aliquid error unde quod ipsum dignissimos ratione exercitationem nulla similique rerum.', '2025-10-04', NULL, 3, 'termine', 'Educatif', 'Application avec C++ Borland builder', 3, '2025-10-03 21:00:00'),
(53, 'Dormir', 'Lorem ipsum dolor sit amet consectetur adipisicing elit. Molestias at consequatur sequi dicta amet odio eius ut eligendi. Dicta numquam dolorem omnis! Odit tenetur expedita consectetur! Suscipit aut placeat reiciendis alias magnam. Enim accusamus eius maxime dolorem numquam recusandae magnam eaque quis, ad minus aperiam perferendis, nesciunt nulla odit fugit fuga. Enim nulla, architecto nam natus quam iusto adipisci veniam fuga quos, provident vitae sed, fugiat porro! Nam, quas ratione!', '2025-10-13', '2025-11-09', 3, 'en_cours', 'Santé et Bien-être', '', 3, '2025-10-04 21:00:00'),
(56, 'Lire une livre', 'Lorem ipsum dolor sit amet consectetur adipisicing elit. Suscipit, minima non quia laboriosam earum iusto aspernatur repellat perferendis debitis optio maxime corporis porro labore iure delectus illo eligendi expedita voluptatibus, ullam voluptatum eos illum. Voluptate, exercitationem quidem dignissimos quasi praesentium ex necessitatibus ut ducimus repellendus inventore commodi recusandae ad, veniam voluptas? Eveniet dolor, dolore non quas veniam, alias, tenetur quos libero eum veritatis exercitationem harum! Blanditiis officia deserunt expedita nisi.', '2025-10-05', '2025-11-05', 1, 'en_cours', 'Loisirs', 'Objectif : Lorem ipsum dolor sit amet consectetur adipisicing elit. Suscipit, minima non quia laboriosam earum iusto aspernatur repellat perferendis debitis optio maxime corporis porro labore iure delectus illo eligendi expedita voluptatibus, ullam voluptatum eos illum. Voluptate, exercitationem quidem dignissimos quasi praesentium ex necessitatibus ut ducimus repellendus inventore commodi recusandae ad, veniam voluptas?', 14, '2025-10-04 21:00:00'),
(57, 'Projet linux', 'Lorem ipsum dolor sit amet consectetur adipisicing elit. Suscipit, minima non quia laboriosam earum iusto aspernatur repellat perferendis debitis optio maxime corporis porro labore iure delectus illo eligendi expedita voluptatibus, ullam voluptatum eos illum. Voluptate, exercitationem quidem dignissimos quasi praesentium ex necessitatibus ut ducimus repellendus inventore commodi recusandae ad, veniam voluptas? Eveniet dolor, dolore non quas veniam, alias, tenetur quos', '2025-10-13', NULL, 2, 'en_cours', 'Educatif', '', 14, '2025-10-04 21:00:00'),
(58, 'Sport', 'Lorem ipsum dolor sit amet consectetur adipisicing elit. Suscipit, minima non quia laboriosam earum iusto aspernatur repellat perferendis debitis optio maxime corporis porro labore iure delectus illo eligendi expedita voluptatibus, ullam voluptatum eos illum. Voluptate, exercitationem quidem dignissimos quasi praesentium ex necessitatibus ut ducimus repellendus inventore commodi recusandae ad, veniam voluptas? Eveniet dolor, dolore non quas veniam, alias, tenetur quos libero eum veritatis exercitationem harum! Blanditiis officia deserunt expedita nisi.', '2025-10-05', NULL, 2, 'en_cours', 'Loisirs', '', 3, '2025-10-04 21:00:00');

-- --------------------------------------------------------

--
-- Structure de la table `utilisateur`
--

CREATE TABLE `utilisateur` (
  `id_ut` int(11) NOT NULL,
  `nom_ut` varchar(250) NOT NULL,
  `email_ut` varchar(100) NOT NULL,
  `password_ut` varchar(200) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Déchargement des données de la table `utilisateur`
--

INSERT INTO `utilisateur` (`id_ut`, `nom_ut`, `email_ut`, `password_ut`) VALUES
(3, 'RATOJOARIMANANTSOA', 'alyratojo@gmail.com', 'mic'),
(4, ' RAKOTO', 'rakoto@gmail.com', 'koto'),
(14, 'Marie', 'marie@gmail.com', 'marie'),
(15, 'Teste', 'teste@gmail.com', 'mic');

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `priorite`
--
ALTER TABLE `priorite`
  ADD PRIMARY KEY (`Code_p`);

--
-- Index pour la table `projet`
--
ALTER TABLE `projet`
  ADD PRIMARY KEY (`Id_p`),
  ADD KEY `idx_id_ut_projet` (`id_ut`),
  ADD KEY `idx_date_fin` (`date_fin`),
  ADD KEY `idx_statut` (`statut_p`),
  ADD KEY `idx_priorite` (`Id_priorite`);

--
-- Index pour la table `utilisateur`
--
ALTER TABLE `utilisateur`
  ADD PRIMARY KEY (`id_ut`),
  ADD KEY `idx_email` (`email_ut`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `priorite`
--
ALTER TABLE `priorite`
  MODIFY `Code_p` int(3) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT pour la table `projet`
--
ALTER TABLE `projet`
  MODIFY `Id_p` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=60;

--
-- AUTO_INCREMENT pour la table `utilisateur`
--
ALTER TABLE `utilisateur`
  MODIFY `id_ut` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=16;

--
-- Contraintes pour les tables déchargées
--

--
-- Contraintes pour la table `projet`
--
ALTER TABLE `projet`
  ADD CONSTRAINT `projet_ibfk_1` FOREIGN KEY (`Id_priorite`) REFERENCES `priorite` (`Code_p`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `ut_projet` FOREIGN KEY (`id_ut`) REFERENCES `utilisateur` (`id_ut`) ON DELETE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
