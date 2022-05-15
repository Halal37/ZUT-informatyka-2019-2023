<?php

require_once __DIR__ . '/vendor/autoload.php';
use Doctrine\ORM\ORMException;
use Doctrine\ORM\Tools\Setup;
use Doctrine\ORM\EntityManager;

$config=Setup::createAnnotationMetadataConfiguration(array(__DIR__ . '/src'), true, null, null, false);

$conn=array(
'dbname'=>'labs',
'user'=>'root',
'password'=>'',
'host'=>'localhost',
'driver'=>'pdo_mysql',
'charset'=>'utf8'

);

$em=EntityManager::create($conn,$config);

?>