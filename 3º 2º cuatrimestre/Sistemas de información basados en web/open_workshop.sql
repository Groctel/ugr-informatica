-- phpMyAdmin SQL Dump
-- version 5.1.0
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: May 27, 2021 at 02:22 PM
-- Server version: 10.5.10-MariaDB
-- PHP Version: 7.4.18

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `open_workshop`
--

-- --------------------------------------------------------

--
-- Table structure for table `Comments`
--

CREATE TABLE `Comments` (
  `id` char(20) COLLATE utf8mb4_unicode_ci NOT NULL,
  `id_event` char(20) COLLATE utf8mb4_unicode_ci NOT NULL,
  `id_author` char(20) COLLATE utf8mb4_unicode_ci NOT NULL,
  `date` datetime NOT NULL DEFAULT current_timestamp(),
  `body` varchar(10000) COLLATE utf8mb4_unicode_ci NOT NULL,
  `edited` tinyint(1) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `Comments`
--

INSERT INTO `Comments` (`id`, `id_event`, `id_author`, `date`, `body`, `edited`) VALUES
('0cc1f8080589a8678aa4', '706cf7ef11251f7440a7', '37c521feed20e0510991', '2021-05-27 14:21:53', 'Qué feo Emacs macho', 0);

--
-- Triggers `Comments`
--
DELIMITER $$
CREATE TRIGGER `generate_comment_id` BEFORE INSERT ON `Comments` FOR EACH ROW IF NEW.id = 0 THEN
    SET NEW.id = substring(MD5(RAND()),1,20);
  END IF
$$
DELIMITER ;

-- --------------------------------------------------------

--
-- Table structure for table `Events`
--

CREATE TABLE `Events` (
  `id` char(20) COLLATE utf8mb4_unicode_ci NOT NULL,
  `title` varchar(256) COLLATE utf8mb4_unicode_ci NOT NULL,
  `id_org` char(20) COLLATE utf8mb4_unicode_ci NOT NULL,
  `date` date NOT NULL,
  `body` text COLLATE utf8mb4_unicode_ci NOT NULL,
  `img1` varchar(512) COLLATE utf8mb4_unicode_ci NOT NULL,
  `img2` varchar(512) COLLATE utf8mb4_unicode_ci NOT NULL,
  `hidden` tinyint(1) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `Events`
--

INSERT INTO `Events` (`id`, `title`, `id_org`, `date`, `body`, `img1`, `img2`, `hidden`) VALUES
('706cf7ef11251f7440a7', 'La pena de Emacs', '9ced6c576e38ec079ff0', '2021-05-29', 'Lorem fistrum al ataquerl condemor dolor aliquip al ataquerl aute labore me cago en tus muelas voluptate ut. Diodenoo apetecan consequat exercitation esse. Se calle ustée al ataquerl ese que llega la caidita tempor va usté muy cargadoo aliqua. Fistro hasta luego Lucas commodo amatomaa ese hombree ese hombree ut consectetur a peich diodenoo ut. Tiene musho peligro me cago en tus muelas te voy a borrar el cerito voluptate.\r\n\r\nTempor tiene musho peligro qui ullamco amatomaa hasta luego Lucas benemeritaar qué dise usteer ut dolore reprehenderit. A gramenawer quietooor velit officia pupita irure cillum cillum está la cosa muy malar de la pradera cillum. Dolore tempor ullamco nisi. Sed officia apetecan esse quis quis amatomaa me cago en tus muelas. Ese pedazo de pecador caballo blanco caballo negroorl a peich por la gloria de mi madre elit jarl.\r\n\r\nDolor ex te va a hasé pupitaa aliquip dolore duis ad qué dise usteer. Enim apetecan officia eiusmod torpedo voluptate aliqua quietooor occaecat a gramenawer. Quietooor a wan pecador nostrud papaar papaar tempor quietooor commodo. Tiene musho peligro mamaar cillum sit amet a wan qué dise usteer aute jarl sit amet. Minim laboris caballo blanco caballo negroorl te voy a borrar el cerito a peich torpedo caballo blanco caballo negroorl va usté muy cargadoo llevame al sircoo irure. A gramenawer apetecan la caidita voluptate benemeritaar ut torpedo.', 'https://upload.wikimedia.org/wikipedia/commons/thumb/0/08/EmacsIcon.svg/1024px-EmacsIcon.svg.png', 'https://upload.wikimedia.org/wikipedia/commons/e/ef/Emacs_Dired_buffers.png', 0),
('9cad8b2f1ff6c5ad7a54', 'Introducción a vim', '9ced6c576e38ec079ff0', '2021-06-02', 'Lorem fistrum benemeritaar mamaar ad caballo blanco caballo negroorl. Nostrud exercitation a peich por la gloria de mi madre pupita te voy a borrar el cerito esse diodenoo occaecat. Benemeritaar et ut dolore sexuarl diodeno ese hombree irure qué dise usteer laboris. Reprehenderit nisi cillum consectetur. Voluptate laboris jarl sed llevame al sircoo aliquip torpedo apetecan esse. Quis te va a hasé pupitaa condemor pecador diodeno ahorarr magna caballo blanco caballo negroorl. Labore qui la caidita quis. Jarl ahorarr dolor laboris reprehenderit.\r\n\r\nA peich reprehenderit se calle ustée quietooor ex ut esse nisi ahorarr sit amet aliqua. Te va a hasé pupitaa irure se calle ustée commodo exercitation dolore et aute. Eiusmod ese que llega magna papaar papaar quis consectetur dolore. Occaecat diodenoo caballo blanco caballo negroorl me cago en tus muelas. Mamaar ese hombree quis hasta luego Lucas.\r\n\r\nA peich hasta luego Lucas elit quis diodenoo. Llevame al sircoo hasta luego Lucas ese pedazo de fistro mamaar esse. Aliqua ut ut hasta luego Lucas no te digo trigo por no llamarte Rodrigor sexuarl dolor llevame al sircoo por la gloria de mi madre. Incididunt labore labore torpedo incididunt a peich consequat te va a hasé pupitaa benemeritaar. No puedor ullamco llevame al sircoo está la cosa muy malar quis ex sit amet a gramenawer se calle ustée cillum benemeritaar. Exercitation llevame al sircoo exercitation ese pedazo de. Ahorarr consequat laboris magna pupita enim no puedor reprehenderit. Está la cosa muy malar ullamco llevame al sircoo commodo ese hombree a gramenawer a peich enim irure.\r\n\r\nMagna nisi sed está la cosa muy malar ad. Reprehenderit incididunt va usté muy cargadoo incididunt duis está la cosa muy malar ahorarr quietooor ese que llega diodenoo. Esse consequat apetecan pecador está la cosa muy malar reprehenderit. Por la gloria de mi madre está la cosa muy malar minim labore condemor aliquip qui irure. Exercitation occaecat commodo por la gloria de mi madre.\r\n\r\nQuis velit nostrud no te digo trigo por no llamarte Rodrigor. Ut de la pradera por la gloria de mi madre llevame al sircoo. No puedor consequat no te digo trigo por no llamarte Rodrigor ut enim ese pedazo de. Te voy a borrar el cerito esse voluptate por la gloria de mi madre tempor incididunt. Eiusmod ut incididunt veniam fistro torpedo eiusmod condemor velit se calle ustée. Esse me cago en tus muelas aliqua officia et mamaar diodeno me cago en tus muelas. A peich consectetur consequat veniam mamaar ut. Minim apetecan hasta luego Lucas sed ahorarr hasta luego Lucas qué dise usteer me cago en tus muelas velit sed.', 'https://upload.wikimedia.org/wikipedia/commons/9/9f/Vimlogo.svg', 'https://i.iinfo.cz/images/603/neovim-1.png', 0),
('9f0276a47751f4d25346', 'Instalación de Arch Linux', '1735154dac53c0c44dda', '2021-05-31', 'Lorem fistrum veniam al ataquerl aliqua a gramenawer caballo blanco caballo negroorl torpedo laboris. Officia tiene musho peligro tempor por la gloria de mi madre me cago en tus muelas fistro quietooor. Labore sexuarl consectetur apetecan cillum. Dolore sit amet exercitation a gramenawer se calle ustée. Amatomaa adipisicing magna tiene musho peligro está la cosa muy malar al ataquerl fistro te voy a borrar el cerito hasta luego Lucas consequat qui. Ut et amatomaa diodeno mamaar está la cosa muy malar a wan.\r\n\r\nTempor mamaar condemor laboris jarl me cago en tus muelas condemor et magna te voy a borrar el cerito caballo blanco caballo negroorl. Benemeritaar pupita no puedor elit veniam. Fistro irure benemeritaar exercitation duis te voy a borrar el cerito ese pedazo de diodenoo. Elit por la gloria de mi madre amatomaa te va a hasé pupitaa. Está la cosa muy malar ese pedazo de benemeritaar nostrud incididunt minim irure sexuarl sit amet. Magna nostrud aliqua eiusmod magna ese hombree consectetur. Ut duis te va a hasé pupitaa consectetur se calle ustée voluptate al ataquerl tempor.\r\n\r\nAmatomaa está la cosa muy malar condemor amatomaa me cago en tus muelas reprehenderit. Nisi jarl apetecan diodenoo ut dolor. Minim eiusmod sed no puedor caballo blanco caballo negroorl diodenoo tempor fistro. La caidita llevame al sircoo va usté muy cargadoo et llevame al sircoo al ataquerl laboris pupita. Al ataquerl ahorarr al ataquerl aliqua magna nostrud apetecan irure adipisicing.', 'https://upload.wikimedia.org/wikipedia/commons/thumb/a/a5/Archlinux-icon-crystal-64.svg/1200px-Archlinux-icon-crystal-64.svg.png', 'https://i.redd.it/q7osc7bvfec21.png', 0),
('ad65c42a66afe025517b', 'Python para todos', '1735154dac53c0c44dda', '2021-06-06', 'Lorem fistrum ese pedazo de al ataquerl duis qui a peich caballo blanco caballo negroorl ex eiusmod ahorarr. Sit amet al ataquerl llevame al sircoo duis aliquip no te digo trigo por no llamarte Rodrigor benemeritaar voluptate diodenoo veniam. Te voy a borrar el cerito ahorarr de la pradera ese hombree minim elit sit amet tempor irure sed. Reprehenderit dolore está la cosa muy malar no puedor está la cosa muy malar ad de la pradera la caidita llevame al sircoo dolor ese hombree. Et a gramenawer no puedor magna occaecat.\r\n\r\nEx occaecat se calle ustée dolor. Cillum magna se calle ustée se calle ustée. Et tiene musho peligro qui hasta luego Lucas magna elit no puedor ahorarr consectetur irure sexuarl. Por la gloria de mi madre está la cosa muy malar torpedo commodo pecador quis al ataquerl. Velit a wan te voy a borrar el cerito magna caballo blanco caballo negroorl torpedo ahorarr laboris jarl enim.\r\n\r\nEsse duis sit amet ese hombree benemeritaar irure ex officia llevame al sircoo caballo blanco caballo negroorl sexuarl. Hasta luego Lucas tempor pecador ese pedazo de por la gloria de mi madre. Ese hombree officia voluptate pupita et. Aute duis commodo caballo blanco caballo negroorl sexuarl labore minim tempor nisi et llevame al sircoo. Incididunt aliqua ad diodeno. Et jarl elit incididunt de la pradera occaecat va usté muy cargadoo consectetur labore papaar papaar amatomaa.', 'https://upload.wikimedia.org/wikipedia/commons/thumb/0/0a/Python.svg/1200px-Python.svg.png', 'https://i.insider.com/558d48066da811f266e177e1?width=2477', 0);

--
-- Triggers `Events`
--
DELIMITER $$
CREATE TRIGGER `generate_event_id` BEFORE INSERT ON `Events` FOR EACH ROW IF NEW.id = 0 THEN
    SET NEW.id = substring(MD5(RAND()),1,20);
  END IF
$$
DELIMITER ;

-- --------------------------------------------------------

--
-- Table structure for table `HasTag`
--

CREATE TABLE `HasTag` (
  `event_id` char(20) COLLATE utf8mb4_unicode_ci NOT NULL,
  `tag` varchar(32) COLLATE utf8mb4_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `HasTag`
--

INSERT INTO `HasTag` (`event_id`, `tag`) VALUES
('706cf7ef11251f7440a7', 'editor'),
('706cf7ef11251f7440a7', 'emacs'),
('9cad8b2f1ff6c5ad7a54', 'editor'),
('9cad8b2f1ff6c5ad7a54', 'linux'),
('9cad8b2f1ff6c5ad7a54', 'vim'),
('9f0276a47751f4d25346', 'arch'),
('9f0276a47751f4d25346', 'foss'),
('9f0276a47751f4d25346', 'instalacion'),
('9f0276a47751f4d25346', 'libre'),
('9f0276a47751f4d25346', 'linux'),
('ad65c42a66afe025517b', 'foss'),
('ad65c42a66afe025517b', 'linux'),
('ad65c42a66afe025517b', 'programacion'),
('ad65c42a66afe025517b', 'python'),
('ad65c42a66afe025517b', 'software');

-- --------------------------------------------------------

--
-- Table structure for table `Tags`
--

CREATE TABLE `Tags` (
  `name` varchar(32) COLLATE utf8mb4_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `Tags`
--

INSERT INTO `Tags` (`name`) VALUES
('arch'),
('editor'),
('emacs'),
('foss'),
('instalacion'),
('libre'),
('linux'),
('programacion'),
('python'),
('software'),
('vim');

-- --------------------------------------------------------

--
-- Table structure for table `Users`
--

CREATE TABLE `Users` (
  `id` char(20) COLLATE utf8mb4_unicode_ci NOT NULL,
  `mail` varchar(100) COLLATE utf8mb4_unicode_ci NOT NULL,
  `name` varchar(100) COLLATE utf8mb4_unicode_ci NOT NULL,
  `pass` char(60) COLLATE utf8mb4_unicode_ci NOT NULL,
  `perm` enum('everyone','moderator','manager','superuser') COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT 'everyone'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `Users`
--

INSERT INTO `Users` (`id`, `mail`, `name`, `pass`, `perm`) VALUES
('1735154dac53c0c44dda', 'taxorubio@correo.ugr.es', 'Atanasio Rubio', '$2y$10$UkKW5AWyN9RVP49SobHUS.PVDzw5ZK5MJ3UnuVwE7GJHfacUoM9Be', 'superuser'),
('37c521feed20e0510991', 'torvalds@linux-foundation.org', 'Linus Torvalds', '$2y$10$DsglrZaKupU/NTCA5X.vXOJf8A77BpXKKEGApjMjxIt6H2jDyYkkK', 'moderator'),
('7a7872a8c4073bb11d09', 'turing@gov.co.uk', 'Alan Turing', '$2y$10$/syYQVFwjVKa2l2Blclm.uGfbjr4PzqayOs5tGPnLB83Z1/VUOnvq', 'superuser'),
('9ced6c576e38ec079ff0', 'evaristo@lapolla.records', 'Evaristo Páramos', '$2y$10$wSI.LjbEn7hAyXR6sFaMgelOJJTlTQIH.IThKKIE8N9ClTHlYx3j2', 'manager');

--
-- Triggers `Users`
--
DELIMITER $$
CREATE TRIGGER `generate_user_id` BEFORE INSERT ON `Users` FOR EACH ROW IF NEW.id = 0 THEN
    SET NEW.id = substring(MD5(RAND()),1,20);
  END IF
$$
DELIMITER ;
DELIMITER $$
CREATE TRIGGER `set_default_permissions` BEFORE INSERT ON `Users` FOR EACH ROW IF NEW.id = 0 THEN
    SET NEW.tipo = 'everyone';
END IF
$$
DELIMITER ;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `Comments`
--
ALTER TABLE `Comments`
  ADD PRIMARY KEY (`id`),
  ADD KEY `id_comentario` (`id_event`),
  ADD KEY `id_autor` (`id_author`) USING BTREE;

--
-- Indexes for table `Events`
--
ALTER TABLE `Events`
  ADD PRIMARY KEY (`id`),
  ADD KEY `id_org` (`id_org`);

--
-- Indexes for table `HasTag`
--
ALTER TABLE `HasTag`
  ADD PRIMARY KEY (`event_id`,`tag`),
  ADD KEY `tag` (`tag`);

--
-- Indexes for table `Tags`
--
ALTER TABLE `Tags`
  ADD PRIMARY KEY (`name`);

--
-- Indexes for table `Users`
--
ALTER TABLE `Users`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `correo` (`mail`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `Comments`
--
ALTER TABLE `Comments`
  ADD CONSTRAINT `Comments_ibfk_1` FOREIGN KEY (`id_author`) REFERENCES `Users` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `Comments_ibfk_2` FOREIGN KEY (`id_event`) REFERENCES `Events` (`id`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `Events`
--
ALTER TABLE `Events`
  ADD CONSTRAINT `Events_ibfk_1` FOREIGN KEY (`id_org`) REFERENCES `Users` (`id`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `HasTag`
--
ALTER TABLE `HasTag`
  ADD CONSTRAINT `HasTag_ibfk_1` FOREIGN KEY (`event_id`) REFERENCES `Events` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `HasTag_ibfk_2` FOREIGN KEY (`tag`) REFERENCES `Tags` (`name`) ON DELETE CASCADE ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
