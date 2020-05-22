<!DOCTYPE html>
<html lang="en">
<head>
<head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <meta http-equiv="content-type" content="text/html; charset=UTF-8">
    <link type="text/css" rel="stylesheet" href="https://unpkg.com/bootstrap/dist/css/bootstrap.min.css"/>
</head>
<body>
	<div class="container">
		<div class="row">
			<div class="col-md-8 col-md-offset-2" style="margin-top: 5%;">
				<div class="row">
                    <?php
                        $connection = mysqli_connect('localhost','root','','tutorial');
                        if(isset($_POST['search'])){
                            $searchKey = $_POST['search'];
                            $sql = "SELECT * FROM users WHERE name LIKE '%$searchKey%'";
                        }else{
                            $sql = "SELECT * FROM users";
                            $searchKey = "";
                        }

                        $result = mysqli_query($connection,$sql);

                    ?>
				<form action="" method="POST"> 
					<div class="col-md-6">
						<input type="text" name="search" class='form-control' placeholder="Search" value="<?php echo $searchKey; ?>" > 
					</div>
					<div class="col-md-6 text-left">
						<button class="btn">Search</button>
					</div>
				</form>

				<br>
				<br>
				</div>
				<table class="table table-bordered">
					<tr>
						<th>Name</th>
						<th>Amount</th>
						<th>City</th>
                    </tr>
                    <?php while($row = mysqli_fetch_object($result)) { ?>
					<tr>
						<td><?php echo $row->name ?></td>
                        <td><?php echo $row->amount ?></td>
                        <td><?php echo $row->city ?></td>
                    </tr>
                    <?php } ?>
                    
				</table>
			</div>
		</div>
	</div>

	<?php
                        $connection = mysqli_connect('localhost','root','','tutorial');
                        if(isset($_POST['search'])){
                            $searchKey = $_POST['search'];
                            $sql = "SELECT * FROM users WHERE name LIKE '%$searchKey%'";
                        }else{
                            $sql = "SELECT * FROM users";
                            $searchKey = "";
                        }

                        $result = mysqli_query($connection,$sql);

                    ?>

					
</body>
</html>