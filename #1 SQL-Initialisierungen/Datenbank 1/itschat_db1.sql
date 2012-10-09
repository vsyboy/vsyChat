-- phpMyAdmin SQL Dump
-- version 3.4.3.2
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Erstellungszeit: 09. Okt 2012 um 12:42
-- Server Version: 5.0.77
-- PHP-Version: 5.2.17

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Datenbank: `usr_web359_7`
--

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `itschat_db1`
--

DROP TABLE IF EXISTS `itschat_db1`;
CREATE TABLE IF NOT EXISTS `itschat_db1` (
  `id` int(11) NOT NULL,
  `receiver_user_id` int(11) NOT NULL,
  `sender_user_id` int(11) NOT NULL,
  `message_id` int(11) NOT NULL,
  `timestamp` timestamp NOT NULL default CURRENT_TIMESTAMP,
  UNIQUE KEY `id_index` (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Daten für Tabelle `itschat_db1`
--

INSERT INTO `itschat_db1` (`id`, `receiver_user_id`, `sender_user_id`, `message_id`, `timestamp`) VALUES
(0, 4, 1, 0, '2012-10-09 10:42:01');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
