// Active LOW relay: LOW = ON, HIGH = OFF
// Relay Pin Assignment
// relayA & relayD = Phase 1 pair (Forward)
// relayB & relayC = Phase 2 pair (Reverse)

void loop() {

  // === Phase 1: Forward Polarity ===
  digitalWrite(relayA, LOW);   // ON
  digitalWrite(relayD, LOW);   // ON
  digitalWrite(relayB, HIGH);  // OFF
  digitalWrite(relayC, HIGH);  // OFF
  delay(10);                   // 10ms conduction

  // --- Dead-Time: Fully cut Phase 1 before Phase 2 fires ---
  digitalWrite(relayA, HIGH);  // OFF
  digitalWrite(relayD, HIGH);  // OFF
  delay(2);                    // 2ms mechanical gap

  // === Phase 2: Reverse Polarity ===
  digitalWrite(relayB, LOW);   // ON
  digitalWrite(relayC, LOW);   // ON
  delay(10);                   // 10ms conduction

  // --- Dead-Time: Fully cut Phase 2 before Phase 1 fires ---
  digitalWrite(relayB, HIGH);  // OFF
  digitalWrite(relayC, HIGH);  // OFF
  delay(2);                    // 2ms mechanical gap

}