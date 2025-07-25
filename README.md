<h1>Gallon Water Depot Management System in C</h1>

<p>This is a C program that implements a simple management system for a <strong>gallon water refill depot</strong>. The system allows the admin to manage customer data, place orders, track gallon stock, and view order histories. It features a console-based menu system and stores data in text files for persistence.</p>

<h2>Features</h2>
<ul>
  <li>Admin login system with authentication.</li>
  <li>Add and search customer data (name, address, phone number).</li>
  <li>Place gallon water orders and calculate total costs.</li>
  <li>Automatically generate unique customer and order IDs.</li>
  <li>View current stock of gallons (default 80 units).</li>
  <li>View order details and update status (e.g., "Belum Diproses", "Selesai").</li>
  <li>Track and display order history.</li>
  <li>Saves data into local <code>.txt</code> files (<code>pelanggan.txt</code>, <code>pesanan.txt</code>).</li>
  <li>Uses standard C libraries for basic functionality: <code>stdio.h</code>, <code>stdlib.h</code>, <code>string.h</code>, and <code>time.h</code>.</li>
</ul>

<h2>⚙How to Run</h2>
<p>To run this program, you need a C compiler such as GCC. Compile the source code using the following command:</p>

<pre><code>gcc gallon-water-depot-management.c -o depot
</code></pre>

<p>Then run the program with:</p>
<pre><code>./depot
</code></pre>

<h2>Admin Credentials</h2>
<ul>
  <li><strong>Username:</strong> radit</li>
  <li><strong>Password:</strong> farma123</li>
</ul>

<h2>Menu Options</h2>
<ol>
  <li>Tambah Pelanggan (Add New Customer)</li>
  <li>Pemesanan Galon (Place Gallon Order)</li>
  <li>Stok Galon (Check Gallon Stock)</li>
  <li>Detail Pesanan (View Order Details)</li>
  <li>Cari Data Pelanggan (Search for Customer)</li>
  <li>Keluar (Exit)</li>
</ol>

<h2>Notes</h2>
<ul>
  <li>Orders reduce stock only if they are not yet marked as "Selesai".</li>
  <li>Files are used as basic databases.</li>
  <li>System is fully console-based.</li>
</ul>

<h2>Have Fun Managing Your Water Depot!</h2>
