<?php

$file_db = "curhat.db";

try {
    $pdo = new PDO('sqlite:$file_db');
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $pdo->setAttribute(PDO::ATTR_EMULATE_PREPARES, false);

    $sql_create = "CREATE TABLE IF NOT EXISTS 'curhat'(
        'id' integer NOT NULL PRIMARY KEY AUTOINCREMENT,
        'nama' text NOT NULL, 
        'created_at' datetime NOT NULL DEFAULT CURRENT_TIMESTAMP)";
    $pdo->exec($sql_create);
} catch (PDOException $e) {
    throw new PDOException($e->getMessage(), (int)$e->getCode());
}

header('Content-Type: application/json');

if ($_SERVER['REQUEST_METHOD'] === 'GET') {
    $query = 'select * from curhat order by created_at desc';
    $stmt = $pdo->prepare($query);
    $stmt->execute();
    $data = $stmt->fetchAll(PDO::FETCH_ASSOC);
    echo json_encode($data);
} elseif ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $nama = $_POST['nama'];
    $konten = $_POST['konten'];
    $query = "insert into curhat (nama, konten) values (?, ?";
    $stmt = $pdo->prepare($query);
    $res = $stmt->execute($nama, $konten);
    if ($res) {
        $data = ['nama' => $nama, 'konten' => $konten];
        echo json_encode($data);
    } else {
        echo json_encode(['error' => $stmt->errorCode()]);
    }
} elseif ($_SERVER['REQUEST_METHOD'] === 'DELETE') {
    # untuk menghapus data dari server
    $id = $_GET['id'];
    $query = "delete from curhat where id = ?";
    $stmt = $pdo->prepare($query);
    $res = $stmt->execute($id);
    if ($res) {
        $data = ['id' => $id];
        echo json_encode($data);
    } else {
        echo json_encode(['error' => $stmt->errorCode()]);
    }
}
