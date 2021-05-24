-- phpMyAdmin SQL Dump
-- version 5.1.0
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: May 24, 2021 at 12:40 PM
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
-- Table structure for table `Comentarios`
--

CREATE TABLE `Comentarios` (
  `id` char(20) COLLATE utf8mb4_unicode_ci NOT NULL,
  `id_evento` char(20) COLLATE utf8mb4_unicode_ci NOT NULL,
  `id_autor` char(20) COLLATE utf8mb4_unicode_ci NOT NULL,
  `fecha` datetime NOT NULL DEFAULT current_timestamp(),
  `contenido` varchar(10000) COLLATE utf8mb4_unicode_ci NOT NULL,
  `editado` tinyint(1) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Triggers `Comentarios`
--
DELIMITER $$
CREATE TRIGGER `generate_comment_id` BEFORE INSERT ON `Comentarios` FOR EACH ROW IF NEW.id = 0 THEN
    SET NEW.id = substring(MD5(RAND()),1,20);
  END IF
$$
DELIMITER ;

-- --------------------------------------------------------

--
-- Table structure for table `Eventos`
--

CREATE TABLE `Eventos` (
  `id` char(20) COLLATE utf8mb4_unicode_ci NOT NULL,
  `título` varchar(256) COLLATE utf8mb4_unicode_ci NOT NULL,
  `id_org` char(20) COLLATE utf8mb4_unicode_ci NOT NULL,
  `fecha` date NOT NULL,
  `descripción` text COLLATE utf8mb4_unicode_ci NOT NULL,
  `img1` varchar(512) COLLATE utf8mb4_unicode_ci NOT NULL,
  `img2` varchar(512) COLLATE utf8mb4_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `Eventos`
--

INSERT INTO `Eventos` (`id`, `título`, `id_org`, `fecha`, `descripción`, `img1`, `img2`) VALUES
('3b4c97b7d507c81dad84', 'Python para todos', '7a7872a8c4073bb11d09', '2021-02-08', 'Lorem fistrum ese pedazo de al ataquerl duis qui a peich caballo blanco caballo negroorl ex eiusmod ahorarr. Sit amet al ataquerl llevame al sircoo duis aliquip no te digo trigo por no llamarte Rodrigor benemeritaar voluptate diodenoo veniam. Te voy a borrar el cerito ahorarr de la pradera ese hombree minim elit sit amet tempor irure sed. Reprehenderit dolore está la cosa muy malar no puedor está la cosa muy malar ad de la pradera la caidita llevame al sircoo dolor ese hombree. Et a gramenawer no puedor magna occaecat.\r\n\r\nEx occaecat se calle ustée dolor. Cillum magna se calle ustée se calle ustée. Et tiene musho peligro qui hasta luego Lucas magna elit no puedor ahorarr consectetur irure sexuarl. Por la gloria de mi madre está la cosa muy malar torpedo commodo pecador quis al ataquerl. Velit a wan te voy a borrar el cerito magna caballo blanco caballo negroorl torpedo ahorarr laboris jarl enim.\r\n\r\nEsse duis sit amet ese hombree benemeritaar irure ex officia llevame al sircoo caballo blanco caballo negroorl sexuarl. Hasta luego Lucas tempor pecador ese pedazo de por la gloria de mi madre. Ese hombree officia voluptate pupita et. Aute duis commodo caballo blanco caballo negroorl sexuarl labore minim tempor nisi et llevame al sircoo. Incididunt aliqua ad diodeno. Et jarl elit incididunt de la pradera occaecat va usté muy cargadoo consectetur labore papaar papaar amatomaa.', 'https://upload.wikimedia.org/wikipedia/commons/thumb/0/0a/Python.svg/1200px-Python.svg.png', 'https://i.insider.com/558d48066da811f266e177e1?width=2477'),
('3c887ede80482aa7f98b', 'Control de versiones con git y GitHub', '1735154dac53c0c44dda', '2021-05-03', 'Lorem fistrum esse ut tempor. Consequat aliqua occaecat apetecan ullamco. Eiusmod quis exercitation nisi diodeno ut commodo commodo quietooor a peich elit. Ahorarr cillum torpedo velit aute dolore sed. La caidita enim voluptate laboris consectetur al ataquerl está la cosa muy malar occaecat. Te voy a borrar el cerito a gramenawer qui elit quietooor exercitation no puedor. Dolor et está la cosa muy malar no puedor apetecan pupita llevame al sircoo. Adipisicing caballo blanco caballo negroorl ahorarr quietooor ese pedazo de.\r\n\r\nTempor adipisicing occaecat tempor. Eiusmod tiene musho peligro nostrud cillum amatomaa qué dise usteer quis exercitation. Está la cosa muy malar et duis ut sexuarl tiene musho peligro sit amet se calle ustée veniam ese hombree de la pradera. Tempor ese pedazo de pupita consectetur ese pedazo de cillum. Ut elit jarl enim de la pradera qué dise usteer magna pupita sexuarl fistro no te digo trigo por no llamarte Rodrigor. No te digo trigo por no llamarte Rodrigor commodo ese que llega nostrud a peich aliquip magna la caidita sexuarl elit benemeritaar.\r\n\r\nQuietooor tempor sit amet ullamco aliquip está la cosa muy malar. Voluptate papaar papaar ut reprehenderit pecador nisi apetecan sed esse me cago en tus muelas pecador. Incididunt caballo blanco caballo negroorl no te digo trigo por no llamarte Rodrigor no te digo trigo por no llamarte Rodrigor enim consequat. Incididunt officia a wan aliqua aute incididunt a peich reprehenderit ullamco elit por la gloria de mi madre. Pecador eiusmod exercitation reprehenderit me cago en tus muelas ut ahorarr ese que llega veniam exercitation no te digo trigo por no llamarte Rodrigor. No puedor dolor te va a hasé pupitaa veniam a wan incididunt irure jarl elit incididunt ex.', 'https://upload.wikimedia.org/wikipedia/commons/thumb/3/3f/Git_icon.svg/768px-Git_icon.svg.png', 'https://danielmiessler.com/images/git_merge_1.png'),
('74bb375699f353abf645', 'Introducción a vim', '1735154dac53c0c44dda', '2020-10-26', 'Lorem fistrum benemeritaar mamaar ad caballo blanco caballo negroorl. Nostrud exercitation a peich por la gloria de mi madre pupita te voy a borrar el cerito esse diodenoo occaecat. Benemeritaar et ut dolore sexuarl diodeno ese hombree irure qué dise usteer laboris. Reprehenderit nisi cillum consectetur. Voluptate laboris jarl sed llevame al sircoo aliquip torpedo apetecan esse. Quis te va a hasé pupitaa condemor pecador diodeno ahorarr magna caballo blanco caballo negroorl. Labore qui la caidita quis. Jarl ahorarr dolor laboris reprehenderit.\r\n\r\nA peich reprehenderit se calle ustée quietooor ex ut esse nisi ahorarr sit amet aliqua. Te va a hasé pupitaa irure se calle ustée commodo exercitation dolore et aute. Eiusmod ese que llega magna papaar papaar quis consectetur dolore. Occaecat diodenoo caballo blanco caballo negroorl me cago en tus muelas. Mamaar ese hombree quis hasta luego Lucas.\r\n\r\nA peich hasta luego Lucas elit quis diodenoo. Llevame al sircoo hasta luego Lucas ese pedazo de fistro mamaar esse. Aliqua ut ut hasta luego Lucas no te digo trigo por no llamarte Rodrigor sexuarl dolor llevame al sircoo por la gloria de mi madre. Incididunt labore labore torpedo incididunt a peich consequat te va a hasé pupitaa benemeritaar. No puedor ullamco llevame al sircoo está la cosa muy malar quis ex sit amet a gramenawer se calle ustée cillum benemeritaar. Exercitation llevame al sircoo exercitation ese pedazo de. Ahorarr consequat laboris magna pupita enim no puedor reprehenderit. Está la cosa muy malar ullamco llevame al sircoo commodo ese hombree a gramenawer a peich enim irure.\r\n\r\nMagna nisi sed está la cosa muy malar ad. Reprehenderit incididunt va usté muy cargadoo incididunt duis está la cosa muy malar ahorarr quietooor ese que llega diodenoo. Esse consequat apetecan pecador está la cosa muy malar reprehenderit. Por la gloria de mi madre está la cosa muy malar minim labore condemor aliquip qui irure. Exercitation occaecat commodo por la gloria de mi madre.\r\n\r\nQuis velit nostrud no te digo trigo por no llamarte Rodrigor. Ut de la pradera por la gloria de mi madre llevame al sircoo. No puedor consequat no te digo trigo por no llamarte Rodrigor ut enim ese pedazo de. Te voy a borrar el cerito esse voluptate por la gloria de mi madre tempor incididunt. Eiusmod ut incididunt veniam fistro torpedo eiusmod condemor velit se calle ustée. Esse me cago en tus muelas aliqua officia et mamaar diodeno me cago en tus muelas. A peich consectetur consequat veniam mamaar ut. Minim apetecan hasta luego Lucas sed ahorarr hasta luego Lucas qué dise usteer me cago en tus muelas velit sed.', 'https://upload.wikimedia.org/wikipedia/commons/9/9f/Vimlogo.svg', 'https://i.iinfo.cz/images/603/neovim-1.png'),
('aff931132c27855d279a', 'La pena de Emacs', '1735154dac53c0c44dda', '2021-09-17', 'Lorem fistrum al ataquerl condemor dolor aliquip al ataquerl aute labore me cago en tus muelas voluptate ut. Diodenoo apetecan consequat exercitation esse. Se calle ustée al ataquerl ese que llega la caidita tempor va usté muy cargadoo aliqua. Fistro hasta luego Lucas commodo amatomaa ese hombree ese hombree ut consectetur a peich diodenoo ut. Tiene musho peligro me cago en tus muelas te voy a borrar el cerito voluptate.\r\n\r\nTempor tiene musho peligro qui ullamco amatomaa hasta luego Lucas benemeritaar qué dise usteer ut dolore reprehenderit. A gramenawer quietooor velit officia pupita irure cillum cillum está la cosa muy malar de la pradera cillum. Dolore tempor ullamco nisi. Sed officia apetecan esse quis quis amatomaa me cago en tus muelas. Ese pedazo de pecador caballo blanco caballo negroorl a peich por la gloria de mi madre elit jarl.\r\n\r\nDolor ex te va a hasé pupitaa aliquip dolore duis ad qué dise usteer. Enim apetecan officia eiusmod torpedo voluptate aliqua quietooor occaecat a gramenawer. Quietooor a wan pecador nostrud papaar papaar tempor quietooor commodo. Tiene musho peligro mamaar cillum sit amet a wan qué dise usteer aute jarl sit amet. Minim laboris caballo blanco caballo negroorl te voy a borrar el cerito a peich torpedo caballo blanco caballo negroorl va usté muy cargadoo llevame al sircoo irure. A gramenawer apetecan la caidita voluptate benemeritaar ut torpedo.', 'https://upload.wikimedia.org/wikipedia/commons/thumb/0/08/EmacsIcon.svg/1024px-EmacsIcon.svg.png', 'https://upload.wikimedia.org/wikipedia/commons/e/ef/Emacs_Dired_buffers.png'),
('beca6c087fee1a31befa', 'Instalación de Arch Linux', '1735154dac53c0c44dda', '2021-08-19', 'Lorem fistrum veniam al ataquerl aliqua a gramenawer caballo blanco caballo negroorl torpedo laboris. Officia tiene musho peligro tempor por la gloria de mi madre me cago en tus muelas fistro quietooor. Labore sexuarl consectetur apetecan cillum. Dolore sit amet exercitation a gramenawer se calle ustée. Amatomaa adipisicing magna tiene musho peligro está la cosa muy malar al ataquerl fistro te voy a borrar el cerito hasta luego Lucas consequat qui. Ut et amatomaa diodeno mamaar está la cosa muy malar a wan.\r\n\r\nTempor mamaar condemor laboris jarl me cago en tus muelas condemor et magna te voy a borrar el cerito caballo blanco caballo negroorl. Benemeritaar pupita no puedor elit veniam. Fistro irure benemeritaar exercitation duis te voy a borrar el cerito ese pedazo de diodenoo. Elit por la gloria de mi madre amatomaa te va a hasé pupitaa. Está la cosa muy malar ese pedazo de benemeritaar nostrud incididunt minim irure sexuarl sit amet. Magna nostrud aliqua eiusmod magna ese hombree consectetur. Ut duis te va a hasé pupitaa consectetur se calle ustée voluptate al ataquerl tempor.\r\n\r\nAmatomaa está la cosa muy malar condemor amatomaa me cago en tus muelas reprehenderit. Nisi jarl apetecan diodenoo ut dolor. Minim eiusmod sed no puedor caballo blanco caballo negroorl diodenoo tempor fistro. La caidita llevame al sircoo va usté muy cargadoo et llevame al sircoo al ataquerl laboris pupita. Al ataquerl ahorarr al ataquerl aliqua magna nostrud apetecan irure adipisicing.', 'https://upload.wikimedia.org/wikipedia/commons/thumb/a/a5/Archlinux-icon-crystal-64.svg/1200px-Archlinux-icon-crystal-64.svg.png', 'https://i.redd.it/q7osc7bvfec21.png');

--
-- Triggers `Eventos`
--
DELIMITER $$
CREATE TRIGGER `generate_event_id` BEFORE INSERT ON `Eventos` FOR EACH ROW IF NEW.id = 0 THEN
    SET NEW.id = substring(MD5(RAND()),1,20);
  END IF
$$
DELIMITER ;

-- --------------------------------------------------------

--
-- Table structure for table `Usuarios`
--

CREATE TABLE `Usuarios` (
  `id` char(20) COLLATE utf8mb4_unicode_ci NOT NULL,
  `correo` varchar(100) COLLATE utf8mb4_unicode_ci NOT NULL,
  `nombre` varchar(100) COLLATE utf8mb4_unicode_ci NOT NULL,
  `pass` char(60) COLLATE utf8mb4_unicode_ci NOT NULL,
  `tipo` enum('everyone','moderator','manager','superuser') COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT 'everyone'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `Usuarios`
--

INSERT INTO `Usuarios` (`id`, `correo`, `nombre`, `pass`, `tipo`) VALUES
('1735154dac53c0c44dda', 'taxorubio@correo.ugr.es', 'Atanasio Rubio', '$2y$10$vjNnM3ITiAfIpp38F9mN0.WN8EV4H6ZS0o62.EDO2.zRAKBZ98s8a', 'superuser'),
('37c521feed20e0510991', 'torvalds@linux-foundation.org', 'Linus Torvalds', '$2y$10$DsglrZaKupU/NTCA5X.vXOJf8A77BpXKKEGApjMjxIt6H2jDyYkkK', 'moderator'),
('7a7872a8c4073bb11d09', 'turing@gov.co.uk', 'Alan Turing', '$2y$10$/syYQVFwjVKa2l2Blclm.uGfbjr4PzqayOs5tGPnLB83Z1/VUOnvq', 'superuser'),
('9ced6c576e38ec079ff0', 'evaristo@lapolla.records', 'Evaristo Páramos', '$2y$10$wSI.LjbEn7hAyXR6sFaMgelOJJTlTQIH.IThKKIE8N9ClTHlYx3j2', 'moderator');

--
-- Triggers `Usuarios`
--
DELIMITER $$
CREATE TRIGGER `generate_user_id` BEFORE INSERT ON `Usuarios` FOR EACH ROW IF NEW.id = 0 THEN
    SET NEW.id = substring(MD5(RAND()),1,20);
  END IF
$$
DELIMITER ;
DELIMITER $$
CREATE TRIGGER `set_default_permissions` BEFORE INSERT ON `Usuarios` FOR EACH ROW IF NEW.id = 0 THEN
    SET NEW.tipo = 'everyone';
END IF
$$
DELIMITER ;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `Comentarios`
--
ALTER TABLE `Comentarios`
  ADD PRIMARY KEY (`id`),
  ADD KEY `id_comentario` (`id_evento`),
  ADD KEY `id_autor` (`id_autor`) USING BTREE;

--
-- Indexes for table `Eventos`
--
ALTER TABLE `Eventos`
  ADD PRIMARY KEY (`id`),
  ADD KEY `id_org` (`id_org`);

--
-- Indexes for table `Usuarios`
--
ALTER TABLE `Usuarios`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `correo` (`correo`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `Comentarios`
--
ALTER TABLE `Comentarios`
  ADD CONSTRAINT `Comentarios_ibfk_1` FOREIGN KEY (`id_autor`) REFERENCES `Usuarios` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `Comentarios_ibfk_2` FOREIGN KEY (`id_evento`) REFERENCES `Eventos` (`id`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `Eventos`
--
ALTER TABLE `Eventos`
  ADD CONSTRAINT `Eventos_ibfk_1` FOREIGN KEY (`id_org`) REFERENCES `Usuarios` (`id`) ON DELETE CASCADE ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
